#include "Batch_Processing_Components/Batch_Processor_Instance/batch_processor.hpp"
#include "Frontend_Components/Frontend_Linkage/frontend.hpp"
#include "Frontend_Components/UI/UI.hpp"

int main() {
    while (true) {
        printMenu();
        uint8_t choice = getMenuChoice();
        switch (choice) {
            case 1: { 
                std::string filePath = getFilePath();
                if (filePath.empty()) {
                    std::cout << "File path cannot be empty. Returning to menu.\n";
                    break;
                }
                BatchProcessor processor(filePath, convertToScaled);
                processor.run();
                break;
            }
            case 2: { 
                std::string filePath = getFilePath();
                if (filePath.empty()) {
                    std::cout << "File path cannot be empty. Returning to menu.\n";
                    break; 
                }
                BatchProcessor processor(filePath, convertToUnscaled);
                processor.run();
                break;
            }
            case 3:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0; 
}
