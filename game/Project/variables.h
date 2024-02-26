#pragma once

#include "pch.h"

extern string questionsArr[18] = { "How many constellations are there? \n \n a. 88 \n b. 39 \n c. 120",
	"How long does each season last on Neptune? \n \n a. 3 months \n b. 30 weeks \n c. more than 40 years",
	"How many minutes was the shortest space flight? \n \n a. 60 minutes \n b. 15 minutes \n c. 3 minutes",
	"What is the only planet not named after a God? \n \n a. Earth \n b. Mars \n c. Venus",
	"How was the first manned space mission to land on the Moon called? \n \n a. Apollo 17 \n b. Apollo 14 \n c. Apollo 11",
	"What planet is nicknamed the 'Red Planet'? \n \n a. Mars \n b. Saturn \n c. Mercury",
	"How long does it take to get to the moon from Earth in a space shuttle? \n \n a. 3 days \n b. 1 hour \n c. 5 hours",
	"Which constellation takes its name from the Latin word for 'twins'? \n \n a. Libra \n b. Gemini \n c. Cancer",
	"How many space shuttles actually flew in space? \n \n a. Three \n b. Eighteen \n c. Five",
	"Neptune has the fastest winds of any planet, what speeds do they reach? \n \n a. 1,000 mph \n b. 1,300 mph \n c. 6,500 mph",
	"Which constellation holds the hottest place in the universe? \n \n a. Virgo \n b. Orion \n c. Draco",
	"Apollo 11 landed in which ocean upon completion of their moon landing mission? \n \n a. Atlantic \n b. Arctic \n c. North Pacific",
	"How long does it take for Venus to rotate once on its axis (in earth days)? \n \n a. 365 \n b. 224 \n c. 12",
	"In which year did man last walk on the Moon? \n \n a. 1972 \n b. 2001 \n c. 1975",
	"How many ring does Uranus have? \n \n a. 200 \n b. 13 \n c. 46",
	"How long is Mercury's year? \n \n a. 88 Earth days \n b. 365 Earth days \n c. 27 Earth days",
	"Who was the first astronaut to walk on the moon? \n \n a. Charles Duke \n b. Neil Armstrong \n c. Buzz Aldrin",
	"Which planet is name after the King of the Roman gods? \n \n a. Jupiter \n b. Neptune \n c. Uranus" };

extern char answers[18] = {
	'a',
	'c',
	'b',
	'a',
	'c',
	'a',
	'a',
	'b',
	'c',
	'b',
	'a',
	'c',
	'b',
	'a',
	'b',
	'a',
	'b',
	'a',
};

extern int questionsLength = 15;

extern bool isAnswerTrue = false;

extern string currentQuestion = "";
