#ifndef RESULTS_H
#define RESULTS_H

#include <stdexcept>
#include <string>
#include <vector>
#include <variant>
#include <cstdint>
#include <unordered_map>
#include <algorithm>

namespace hydro
{
    class ResultsException : public std::runtime_error
    {
    public:
        explicit ResultsException(const std::string& message)
            : std::runtime_error(message) {}
    };

    enum class ResultStatus
    {
        success, failure, partial_success
    };

    // alias for results value (flow rate, pressure ...)
    using result_value = std::variant<double, uint32_t, std::string>;

    class Results
    {
    private:
        double simulationtime;
        ResultStatus status;                        /* results status : success, failure, partial success */
        std::unordered_map<uint32_t, result_value> results; /* map of results */
        std::vector<std::string> errors;            /* errors during simulation */
    public:
        Results(double simulation_time, ResultStatus _status = ResultStatus::success)
            : simulationtime(simulation_time), status(_status) {}

        // delete copy sonstructor and copy assignment
        Results (const Results&) = delete;
        Results& operator= (const Results&) = delete;

        // move constructor and move assignmet
        Results (Results&&) noexcept = default;
        Results& operator= (Results&&) noexcept = default;

        void add_result(uint32_t key, const result_value& value)
        {
            if (results.find(key) != results.end()){
                throw ResultsException(key + " : result already exists");
            }
            results[key] = value;
        }

        template <typename T>
        T get_result (const uint32_t key) const
        {
            auto it = reslts.find(key);
            if(it == results.end()){
                throw ResultsException (key + " : result not found");
            }
            if(auto val == std::get_if<T>(&(it)->second)){
                return *val;
            }
            else{
                throw ResultsException ("type mismatch for result key : " + key);
            }
        }

        bool validate() const
        {
            // check if flow rate is positive values
            for(const auto& [key, value] : results){
                if(auto val = std::get_if<double>(&value)){
                    if(*val < 0.0){
                        return false;
                    }
                }
            }
            return true;
        }

        void clear_results()
        {
            results.clear();
            status = ResultStatus::success;
            errors.clear();
        }

        std::string export_results() const
        {
            std::string export_data;
            for(const auto& [key, value] : results)
            {
                export_data += key + " : ";
                // below parses data in value - may change due to size of value object
                // std::visit([&export_data](auto&& arg){
                //     export_data += std::to_string(arg) + "\n";
                // }, value);
            }
            return export_data;
        }

        void add_error(const std::string& error_msg)
        {
            errors.push_back(error_msg);
        }

        double get_simulation_time() const noexcept
        {
            return simulationtime;
        }

        ResultStatus get_status() const noexcept
        {
            return status;
        }

        ~Results() noexcept = default;
    };
} // namespace hydro


#endif  // RESULTS_H