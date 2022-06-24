#include <iostream>
#include <cxxopts.hpp>
#include <fmt/format.h>
#include <range/v3/view.hpp>

namespace view = ranges::views;

int fib(int x) {
    int a = 0;
    int b = 1;

    for (int it : view::repeat(0) | view::take(x)) {
        (void)it;
        int tmp = a;
        a += b;
        b = tmp;
    }

    return a;
}

int main(int argc, char** argv) {
    cxxopts::Options options("sample-project", "Print the fibonacci sequence up to a value 'n'");

    // Add options
    auto add = options.add_options();
    add("h,help", "Print this help message", cxxopts::value<bool>());
    add("n,value", "The sequence index to count up to", cxxopts::value<int>()->default_value("10"));
    options.parse_positional({"value"});

    // Parse 'em
    auto parsed_args = options.parse(argc, argv);

    // Need help?
    if (parsed_args.count("help") > 0)
    {
      std::cout << options.help() << std::endl;
      exit(0);
    }
    
    auto n = parsed_args["value"].as<int>();

    for (int x : view::iota(1) | view::take(n)) {
        fmt::print("fib({}) = {}\n", x, fib(x));
    }
}
