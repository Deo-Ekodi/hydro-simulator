#ifndef OUTPUT_HANDLER_H
#define OUTPUT_HANDLER_H

namespace hydro
{
    class OutputHandler
    {
        public:
        OutputHandler(){
            ;
        }

        OutputHandler (const OutputHandler&) = delete;
        OutputHandler& operator= (const OutputHandler&) = delete;

        OutputHandler (OutputHandler&&) noexcept = default;
        OutputHandler& operator= (OutputHandler&&) noexcept = default;
    };
} // namespace hydro


#endif