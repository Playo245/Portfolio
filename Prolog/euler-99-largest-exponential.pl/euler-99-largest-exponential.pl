% Import necessary libraries
:- use_module(library(readutil)). % For reading files line by line
:- initialization(main, main).   % Ensure 'main' is the entry point when the script is run

% Main entry point of the script
main :-
    % Retrieve command line arguments
    current_prolog_flag(argv, Args),
    % Check if exactly one argument (filename) is provided
    (   Args = [Filename] ->
        % If filename is provided, process the file
        process_file(Filename)
    ;   % If not, print usage instructions
        write('Usage: swipl -s euler-99-largest-exponential.pl <filename>'), nl
    ).

% Process the file specified by Filename
process_file(Filename) :-
    % Read the file into a list of lines
    file_lines(Filename, Lines),
    % Find the line with the highest computed value
    find_highest(Lines, 1, 0, 0, HighestLine),
    % Output the result
    (   HighestLine = 0 -> 
        true  % Do nothing if no valid line found
    ;   format('~d~n', [HighestLine])  % Print the line number
    ).

% Read the given file into a list of lines
file_lines(Filename, Lines) :-
    % Open the file
    open(Filename, read, Stream),
    % Read the stream to a list of lines
    read_stream(Stream, Lines),
    % Close the file stream
    close(Stream).

% Recursively read from stream into a list of lines
read_stream(Stream, Lines) :-
    % Read a line from the stream
    read_line_to_string(Stream, Line),
    % Check if the end of the file is reached
    (   Line \= end_of_file ->
        % If not, continue reading the rest
        read_stream(Stream, RestLines),
        % Add the read line to the list
        Lines = [Line | RestLines]
    ;   % If end of file, return an empty list
        Lines = []
    ).

% Recursively find the line with the highest value
find_highest([], _, HighestLine, _, HighestLine).
find_highest([Line|Rest], LineNum, CurrentHighest, CurrentTotal, HighestLine) :-
    % Split the line into base and exponent
    split_line(Line, Base, Exponent),
    % Compute the value using logarithm
    Total is Exponent * log(Base),
    % Compare with the current highest total
    (   Total > CurrentTotal ->
        % If higher, update the highest line and total
        NewHighest = LineNum,
        NewTotal = Total
    ;   % Otherwise, keep the current highest
        NewHighest = CurrentHighest,
        NewTotal = CurrentTotal
    ),
    % Move to the next line
    NextLineNum is LineNum + 1,
    % Continue with the rest of the lines
    find_highest(Rest, NextLineNum, NewHighest, NewTotal, HighestLine).

% Split a line into base and exponent parts
split_line(Line, Base, Exponent) :-
    % Split the line by the comma
    split_string(Line, ",", "", [BaseStr, ExponentStr]),
    % Convert string representations to numbers
    number_string(Base, BaseStr),
    number_string(Exponent, ExponentStr).
