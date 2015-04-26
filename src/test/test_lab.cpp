#include <iostream>
#include <QString>
#include <QDebug>

//Includes for tested classes
#include "controller/data_key_value_container.h"

/** This is our testclass which purpose to avoid messing up the finished
 * classes.
 * @brief The test_lab class
 */
class test_lab {

public:
    test_lab();
    ~test_lab();

    void test_data_cont_template();
};

/** Test for data key value container
 * @brief test_lab::test_data_cont_template
 */
void test_lab::test_data_cont_template(){

    //Tester å legge inn en QStringi template klassen
//    data_key_value_container<QString, QString> dat; //fungerer
    data_key_value_container<const char*, const char*> dat;
    dat.push("Test", "Text");
    dat.push("Test", "Text2");
    dat.push("Test3", "Text3");
    dat.push("Test4", "Text4");
    dat.print_data();

    //Tester å slette en verdi
    std::cout << "Sletter siste verdi" << std::endl;
    dat.pop();
    dat.print_data();

    //Tester å hente siste verdi
    std::cout << "Henter siste verdi" << std::endl;
    pair<const char*, const char*> temp_p = dat.top();
    dat.top();
    std::cout << temp_p.first << ", " << temp_p.second << std::endl;
}
