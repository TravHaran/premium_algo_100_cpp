#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

int main(){
    std::string file1 = "premium100_expansion.txt";
    std::string file2 = "top150_expansion.txt";
    std::unordered_set<std::string> completed;
    std::unordered_set<std::string> todo;
    
    // get completed problems from file1
    std::ifstream file(file1);
    if(file.is_open()){
        std::cout<<"EXTRACTING COMPLETED PROBLEMS"<<std::endl;
        std::string line;
        while(getline(file, line)) {
            // check if line starts with "-"
            if(line.rfind("- ", 0) == 0){
                // completed.insert()
                std::string extracted = line.substr(2);
                size_t end = extracted.find_last_not_of(" \t");
                if (end != std::string::npos)
                    extracted = extracted.substr(0, end + 1);
                // std::cout<<extracted.size()<<std::endl;
                completed.insert(extracted);
            }
        }
        // Close the file when done
        file.close();
    } else {
        std::cerr<<"unable to open file"<<std::endl;
    }
    // get completed problems from file2
    std::ifstream secondFile(file2);
    if(secondFile.is_open()){
        std::cout<<"EXTRACTING COMPLETED PROBLEMS"<<std::endl;
        std::string line;
        while(getline(secondFile, line)) {
            // check if line starts with "-"
            if(line.rfind("- ", 0) == 0){
                // completed.insert()
                std::string extracted = line.substr(2);
                size_t end = extracted.find_last_not_of(" \t");
                if (end != std::string::npos)
                    extracted = extracted.substr(0, end + 1);
                // std::cout<<extracted.size()<<std::endl;
                completed.insert(extracted);
            }
        }
        // Close the file when done
        secondFile.close();
    } else {
        std::cerr<<"unable to open file"<<std::endl;
    }
    // get todo problems from file 1
    std::ifstream newfile(file1);
    if(newfile.is_open()){
        std::cout<<"EXTRACTING TODO PROBLEMS"<<std::endl;
        std::string line;
        while(getline(newfile, line)) {
            // Check if the line is indented (starts with whitespace)
            if (!line.empty() && line.substr(0, 4) == "    ") {
                size_t dash_pos = line.find("- ");
                
                std::string extracted = line.substr(dash_pos + 2);

                // Remove trailing whitespace
                size_t end = extracted.find_last_not_of(" \t");
                if (end != std::string::npos)
                    extracted = extracted.substr(0, end + 1);

                if(!completed.count(extracted)) todo.insert(extracted);
            }
        }
        // Close the file when done
        newfile.close();
    } else {
        std::cerr<<"unable to open file"<<std::endl;
    }
    // get todo problems from file 2
    std::ifstream newfile2(file2);
    if(newfile2.is_open()){
        std::cout<<"EXTRACTING TODO PROBLEMS"<<std::endl;
        std::string line;
        while(getline(newfile2, line)) {
            // Check if the line is indented (starts with whitespace)
            if (!line.empty() && line.substr(0, 4) == "    ") {
                size_t dash_pos = line.find("- ");
                
                std::string extracted = line.substr(dash_pos + 2);

                // Remove trailing whitespace
                size_t end = extracted.find_last_not_of(" \t");
                if (end != std::string::npos)
                    extracted = extracted.substr(0, end + 1);

                if(!completed.count(extracted)) todo.insert(extracted);
            }
        }
        // Close the file when done
        newfile2.close();
    } else {
        std::cerr<<"unable to open file"<<std::endl;
    }

    std::vector<std::string> problems(todo.begin(), todo.end());
    std::sort(problems.begin(), problems.end());
    // for(auto& p : problems) std::cout<<p<<std::endl;
    std::ofstream outfile("output.md");
    // Check if the file was successfully opened
    if (outfile.is_open()) {
        std::cout<<"WRITING TO OUTPUT FILE"<<std::endl;
        // Write each string from the vector to a new line in the file
        for (const auto& line : problems) {

            outfile << "- [ ] " + line << std::endl;  // Write string and add a newline
        }

        outfile.close();  // Close the file after writing
    } else {
        std::cerr << "Unable to open file for writing" << std::endl;
    }
};
