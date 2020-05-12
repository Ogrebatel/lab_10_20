// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#include <iostream>
#include <rocksdb/db.h>
#include <rocksdb/slice.h>
#include <rocksdb/options.h>
#include "picosha2.h"
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/console.hpp>

using rocksdb::DB;
using rocksdb::DBOptions;
using rocksdb::ColumnFamilyOptions;
using rocksdb::ReadOptions;
using rocksdb::WriteOptions;
using rocksdb::Options;
using rocksdb::Status;
using rocksdb::ColumnFamilyDescriptor;
using rocksdb::ColumnFamilyHandle;


const char output_format[] = "[%Severity%] %Message%";

class rocksdb_hash{
public:
    rocksdb_hash(const std::string &_path_to_db,
                 const std::string &_path_to_output_db);

    void print_db();
    void print_output_db();
    void create_hash_db();

    void close_db();

    void open_output();
    void log_init();


private:
    Status s;

    DB* input_db;
    DB* hash_db;

    std::string path_to_output_db;

    std::vector<ColumnFamilyDescriptor> column_families;
    std::vector<ColumnFamilyHandle*> handles;
    std::vector<std::string> list_column_families;

    std::vector<ColumnFamilyDescriptor> o_column_families;
    std::vector<ColumnFamilyHandle*> o_handles;

};
#endif // INCLUDE_HEADER_HPP_
