#include "wwm.hpp"

void WasteWaterModel::setup_pipe_network(std::unordered_map<std::string, std::vector<variantType>>& data)
{
    uint32_t index = 0;
    for (const auto& pair : data) {
        if (index < data.size()) {
            Pipe pipe;
            if (pair.first == "ID"){
                pipe.set_id(std::get<uint32_t>(pair.second.at(index)));
            }
            if (pair.first == "Node1") {
                // Node* node = new Node;
                Node node;
                node.set_id(std::get<uint32_t>(pair.second.at(index)));
                pipe.set_start_node(node);
            }
            if (pair.first == "Node2") {
                // Node* node = new Node;
                Node node;
                node.set_id(std::get<uint32_t>(pair.second.at(index)));
                pipe.set_end_node(node);
            }
            if (pair.first == "Diameter") {
                pipe.set_diameter(std::get<double> (pair.second.at(index)));
            }
            if (pair.first == "Length") {
                pipe.set_length (std::get<double> (pair.second.at(index)));
            }
            pipes.push_back (pipe);
            ++index;
        }
    }
}
void WasteWaterModel::log_pipes () const
{
    std::cout << "numbeer of pipes : " << pipes.size() << std::endl;
    std::cout << "id" << "\t" << "start_node_id" << "\t" << "end_node_id" << "\t" << "length" << "\t" << "diameter" << std::endl;
    for (const auto& pipe : pipes) {
        std::cout << pipe.id << "\t" << pipe.start_node.id << "\t" << pipe.end_node.id << "\t" << pipe.length << "\t" << pipe.diameter << std::endl;
    }
    std::cout << "done" << std::endl;
}