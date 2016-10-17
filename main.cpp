#include <iostream>
#include <sstream>
#include <cstdlib>
#include "./list_src/list_tf.h"
#include "list_err.h"
#include <fstream>


using namespace std;


int main(int argc, char *argv[])
{

    if(argc != 3){
        std::cout<<"BAD NUMBER ARGUMENTS"<<std::endl;
        return -1;
    }

    std::ifstream inp_file;
    std::ofstream out_file;
    inp_file.open(argv[1], std::ifstream::binary);
    out_file.open(argv[2], std::ofstream::binary);

    if(!inp_file.is_open() || !out_file.is_open()){
        std::cout<<"BAD OPEN FILE"<<std::endl;
        return -1;
    }

    try
    {
        List list;
        int value = 0;
        while(inp_file >> value){

            list.push_back(value);
        }


        // ЭТО НА ВОПРОС =====================================
//        std::cout<<"list[0]"<<list[0]->getData()<<std::endl;
//        std::cout<<"list[1]"<<list[1]->getData()<<std::endl;
//        Node *f = list[0];
//        Node *s = list[1];

//        if(f > (s) ){
//            std::cout<<"list[0] > list[1]"<<std::endl;
//        }
//        else{
//            std::cout<<"list[1] > list[0]"<<std::endl;
//        }
        //====================================================


        list.show_list();
        std::cout<<"=====BUBBLE_SORT====="<<std::endl;
        bubble_sort_list_byPointer(list);
//        bubble_sort_list_byData(list);
        list.show_list();

        while (!list.isempty()){

            int out_data = list.pop_front();
            out_file<<out_data<<" ";
        }

        out_file<<std::endl;

    }
    catch(list_err ret){
        std::cout<<ret<<" "<<list_err_str[-ret]<<std::endl;
    }

    inp_file.close();
    out_file.close();

    return 0;
}
