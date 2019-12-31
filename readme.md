Recursion in a Pitch Field
==========================

Simple program that models the path traveled by individual pitches of a melody 
as they are transposed through a pitch field. In other words, these pitches
are transposed by a set of diatonic intervals a number of times and the number of 
times that discrete pitches occur is counted. The idea is an attempt to model
the types of recursive algorithms used to generate strange attractors and other
similar types of chaotic symmetries. 

As in it's a music by numbers generator. Recurring pitches will be *colored*
according to a statistical distribution. Color in this case refers to the 
use of a specific type of orchestration to differentiate between pitches. 
That's not part of the program, but maybe it helps to know.

Code has been generated from pseudocode, so the
comments *should* convey a detailed description of the idea and what's happening.

This is a test version that tries to generate a model of one path from an initial pitch.
It's buggy, at the moment it's returning a LNK2005 error due to some multiple definition 
that's proving tricky to find.
