#pragma once

#include <iostream>
#include <vector>
#include <string>

struct Pair {
    public:
    int key;
    std::string val;

    Pair(int key, std::string val);
};

class ArrayHash {
    private:
    std::vector<Pair *> buckets;

    public:

    /**
     * ArrayHash Constructor with size of 100
     */
    ArrayHash();

    /**
     * ArrayHash Destructor
     */
    ~ArrayHash();

    /**
     * Hash function
     * @param key the key to be hashed
     * @return hashed index of buckets
     */
    int hash(int key);

    /**
     * Get the string by key
     * @param key the given key
     * @return the string of given key
     */
    std::string get(int key);

    /**
     * Add new key-value pair into buckets
     * @param key the given key
     * @param val the given value
     */
    void put(int key, std::string val);

    /**
     * Remove a key from buckets
     * @param key the given key
     */
    void remove(int key);

    /**
     * Get all key-value pairs in buckets
     * @return vector of Pair
     */
    std::vector<Pair *> getPairs();

    /**
     * Get all key in buckets
     * @return vector of key
     */
    std::vector<int> getKeys();

    /**
     * Get all value in buckets
     * @return vector of value
     */
    std::vector<std::string> getValues();

    /**
     * Print all key-value pairs
     */
    void print();
};
