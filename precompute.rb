#!/usr/bin/env ruby

# I determined that the longest word is 25chars (including terminator)
MAX_WORD_LENGTH = 32


words = File.readlines("words").sort.uniq

File.open("precomputed.c", "w") do |output|
  output.puts "#define WORD_COUNT #{words.count}"
  output.puts "#define WORD_LENGTH #{MAX_WORD_LENGTH}"
  output.puts "const char words[WORD_COUNT][WORD_LENGTH] = {"

  words.each do |word|
    word = word.chomp
    block = word + ("\\0" * (MAX_WORD_LENGTH - 1 - word.length))

    output.puts "  \"#{block}\","
  end

  output.print "};"
end
