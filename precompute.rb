#!/usr/bin/env ruby

# I determined that the longest word is 25chars (including terminator)
words = File.readlines("words").sort.uniq

File.open("precomputed.c", "w") do |output|
  output.puts "#define WORD_COUNT #{words.count}"
  output.puts "const char words[WORD_COUNT][32] = {"

  words.each do |word|
    word = word.chomp
    block = word + ("\\0" * (31 - word.length))

    output.puts "  \"#{block}\","
  end

  output.print "};"
end
