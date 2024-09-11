#include "wwm.hpp"

void WasteWaterModel::setup_pipe_network(InputHandler& input)
{
    uint32_t index = 0;
    uint32_t number_of_pipes = input.rows();

    std::unordered_map<std::string, std::vector<variantType>> data = input.get_input_data();

    std::string ID = "ID", Diameter = "Diameter", Node1 = "Node1", Node2 = "Node2", Length = "Length";

    std::vector<variantType> id = input.get_column_data(ID);
    std::vector<variantType> length = input.get_column_data(Length);
    // std::vector<variantType> node1 = input.get_column_data(Node1);
    // std::vector<variantType> node2 = input.get_column_data(Node2);
    std::vector<variantType> diameter = input.get_column_data(Diameter);

    while (index < number_of_pipes) {
        Pipe pipe;
        pipe.id = std::get<uint32_t>(id.at(index));
        pipe.diameter = std::get<double>(diameter.at(index));
        pipe.length = std::get<double>(length.at(index));
        pipes.push_back(pipe);
        ++index;
    }
}

void WasteWaterModel::log_pipes() const
{
    std::cout << "number of pipes : " << pipes.size() << std::endl;
    std::cout << "id" << "\t" << "length" << "\t" << "diameter" << std::endl;
    for (const auto &pipe : pipes)
    {
        // std::cout << pipe.id << "\t" << pipe.start_node.id << "\t" << pipe.end_node.id << "\t" << pipe.length << "\t" << pipe.diameter << std::endl;
        std::cout << pipe.id << "\t" <<  pipe.length << "\t" << pipe.diameter << std::endl;
    }
    std::cout << "done" << std::endl;
}