#!/usr/bin/env ruby

# I determined that the longest word is 25chars (including terminator)
words = File.readlines("words")

File.open("precomputed.bin", "w") do |output|
  words.each do |word|
    word = word.chomp
    block = word + ("\0" * (25 - word.length))
    
    output.print block
  end
end