// #include <iostream>
// #include <vector>
// #include <fstream>
// #include <string>
// #include <sstream>

// using namespace std;

// int main(){
//     // vector<vector<float>> Adj_Matrix;

//     // fstream fin;
//     // fin.open("Graph\\Adjacency_Matrix_Preprocess", ios::in);


//     string fname = "Adjacency_Matrix_Preprocess.csv";
 
//     // vector<vector<string>> content;
//     // vector<string> row;

//     vector<vector<float>> content;
//     vector<float> row;
    
//     string line, word;
 
//     fstream file (fname, ios::in);
//     if(file.is_open()){
//         while(getline(file, line)){
//             row.clear();
 
//             stringstream str(line);
 
//             while(getline(str, word, ','))
//             row.push_back(stof(word));
//             content.push_back(row);
//         }       
//     } else cout<<"Could not open the file\n";
 
//     for(int i=0;i<content.size();i++){
//         for(int j=0;j<content[i].size();j++){
//             cout<<content[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
//     return 0;
// }