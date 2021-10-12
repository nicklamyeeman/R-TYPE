/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** generate_json
*/

#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/optional.hpp>
#include <sstream>
#include <fstream>
#include <cstdlib>

int main()
{
    boost::property_tree::ptree pt;
    pt.put("Test", "string");
    pt.put("Test2.inner0", "string2");
    pt.put("Test2.inner1", "string3");
    pt.put("Test2.inner2", 1234);

    std::stringstream ss;
    boost::property_tree::json_parser::write_json(ss, pt);

    std::ofstream myfile;
    myfile.open ("example.json");
    myfile << ss.str();
    myfile.close();

    return 0;
}