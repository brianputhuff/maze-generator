# MAZE GENERATOR

Copyright 2019 Brian Puthuff

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


## Description

This program generates a maze to standard out.

## Running from the command line

To generate a maze, run the executable.
If no additional arguments are applied, the default maze is 9 x 9.

```
./maze



#########
#       #
# ### ###
# #   # #
# # ### #
# #     #
# #######
#       #
#########



```

You can set a horizontal width and vertical width using command line arguments.
Example: Generate a maze with a width of 49 cells and a height of 13 cells.

```
./maze 49 13



#################################################
#         #     #   #                   #       #
# ##### ### # # # # # ##### ##### ####### ### ###
# #   # #   # # # # # #   # #     #       # #   #
# # # ### ### # ### # # # # ####### ####### ### #
# # #     #   #     # # #   #       #       # # #
# # ####### ######### # ##### ######### ### # # #
# # #   #   #         #       #       # # # # # #
# # # # # # # ##################### # # # # # # #
# # # # # # # #                     # # #   #   #
# # ### # ### ### ################### # # #######
#       #         #                     #       #
#################################################



```

You can set a square maze (horizontal width and vertical width the same)  using a single command line argument..
Example: Generate a maze with a width of 49 cells and a height of 13 cells.

```
./maze 23



#######################
# #       #   #       #
# # ### # # # ### # # #
# #   # #   #   # # # #
# ### # ####### ### # #
#     #   #   #     # #
# ####### # # ####### #
# #   # #   #   #     #
# # # # ####### # #####
# # # #   #     # #   #
# # # ### # ##### # ###
# # #   # # #   # #   #
# # ### # # ### # ### #
#   #   # #   #       #
##### ### ### ####### #
# #   #     #     # # #
# # ##### ####### # # #
# # #     #       #   #
# # # ### # ###########
#   # #   #   #     # #
# ### # ##### # ### # #
#     #     #     #   #
#######################



```

## Odd dimensions
If you sepcify a width or height that is of even value, the generated maze will adjust to the preceeding odd value where applicable. So if you specify a maze that has 100 cell width, it will default to 99 cell width.

## Smallest maze
If you specify a value that is less than 3 for width or height, the respective dimension will default to 3. Keep in mind, a 3 x 3 maze is just a box, and not very interersting.

## Random generation
Re-running the program will yield new maze designs. Have fun with it.

## Pipe it to a text file!

```
./maze > out.txt



#########
#       #
# #######
#       #
####### #
#       #
####### #
#       #
#########



```

```
./maze 99 49 > out.txt



###################################################################################################
#           #   #                   #   #             #             #         #           #       #
# # ####### # ### ### ############# # ### ### ####### # # ######### # ##### # # ##### ### # ##### #
# #     # # #       #           #   # #   # # #   #   # #   #   #   # #     # # #   #   # # #     #
# ##### # # ####### ########### # ### # ### # # # ### # ### # # # ##### ##### ### # ### # # # ### #
#   #   # # #   #   #       #   #   #       #   #   # # #   # # # #     #   #     #   # # # #   # #
### # ### # # # ##### ##### # ##### ######### ##### ### # ### # # # ##### ########### # # # ### ###
#   # #   #   #       #     #     #         #     #   # # #   # # # #           #   #   # #   #   #
# ### # # ############# ######### ######### ### ##### # # ### # # # ######### # # # ##### ####### #
#   # # #     #       #       #   #     # # #   #   # # #   # # # #   #     # # # #     #       # #
# ### # # ### # # ########### # ##### # # # ##### # # # ### # ### # # # ### # # # # # ######### # #
# #   # # #   # #         # #   #     #   #     # #   #   # #     # # # # # # #   # # #   #     # #
# # ### # ### # ####### # # ####### ########### # ### ### # ##### ### # # # ####### ### # # ##### #
# # #   #   # #   #     #         # #   #         # #   # # #   #   #     #     #   #   # # #     #
### # ##### # ##### ############# # # # # ######### ### # # # # ### ### ####### # ### ### # ##### #
#   # #     # #     #   # #   #     # #   # #     #     # # # # # #   # #     # #     # # # #     #
# ##### ##### # ### # # # # # # ##### ##### # ### ### ### # # # # ### ### ### # # ##### # # # #####
# #     #       #   # # #   # # #   # #     #   #   # #   #   # #   #     # #   # #     #   #     #
# # # ### ####### ### # # ### # # # # # ### ### ### ### ####### # # ####### ##### # ### ######### #
# # #   # #     #   # # #   #   # #   # #   #   # # #     #     # # #         # # # # #           #
# ##### ### ### ### # # # ####### ##### ##### ### # # ##### ##### # ##### ### # # # # ### ####### #
#     #     #   #   # # # #     # #     #         #     #   #     #   #   #   # # #   #   #     # #
##### # ##### ##### # # ### ### # ##### # ############### ### # ##### # ### ### # ### # ##### # # #
#     # #   #     # # #     # #   #     #   # #         # #   # #       # # #   #   # #     # #   #
# ####### # # ### # # ####### ##### # ##### # # ####### # ### # # ####### # ### ### ##### # #######
# #       # #   # # #     #         # #   #   #     #   #   # # # #     # #       #     # #       #
# # ####### ### # ####### # ########### # ### ##### # ### # # # ### ### # ####### ##### # ####### #
#   #       #   #   #       #     #     #   # #   # # #   # # #     # # #         #     #     # # #
# ### ####### ##### # ####### ### # ####### # ### # # # ### # ####### # ########### ######### # # #
#   # #     # #     # #   #   # #     #     #     # # # #   # #     # #   #       #   #   #     # #
##### # ##### # ##### # ### ### ####### ### ### ### # # # ### # ### # ### # ##### ### # # ####### #
#     # #     #     # #   # #   #       #   # # #   # # # #     #       #   #     # #   # #       #
# ##### # ######### # ### # # # # ####### ### # # ### ### ####### ########### ### # ##### # ##### #
# #         #     # #     # # # #     #       # # #       #   #   #   #     # #         #   # #   #
# ########### ### # ##### # # # ##### ######### # ######### # ##### # # ### # ######### ##### # ###
#             #   #       # # #   #   #   #   # # #   #     # #     #     # #         #       # # #
# ############# ### ####### # ### # ### # # # # # # # # ##### # ########### # ####### ######### # #
#   #         # #     # #   # #   #     #   #   #   # #   #   #         #   #   #   # #   #     # #
### # ######### ##### # # ### # ##################### ### # ##### ##### # # ##### # # # # # ##### #
# # #         # #   #   # #   #             #   #       # # #   # #   # # # #     # # # # # #     #
# # ######### # # # ### # # ############# # # # # ####### # # # # # # # # ### ##### # # # # # # ###
# #           #   #   # # #   #     #   # #   # #       # # # #   # # # #     #     # # #   # #   #
# ########### ####### ### ### ### ### # # ##### ####### # # # ##### # # ####### ##### # ######### #
#   #         #     #   #   # #   #   #   #   # # #     # #       # # #   #     #     #   #   #   #
# # # ########### ##### ### # # ### ######### # # # ##### ######### # ##### ##### # # ### # # # # #
# #   #         #     #   # #   #   # #       #   #   #   #   #   # #   #   #   # # #   #   #   # #
# ######### ### ### # # ### ##### ### # ### ##### ### # ### # ### # ### # ### # # # ############# #
#           #       # #           #       #         #       #   #   #     #   #   #               #
###################################################################################################



```

## Compiling
Maze generator is comprised of a single C source file ```main.c```. There is a ```makefile``` that you can use to compile or customize for your preferred compiler and options. To compile, use the ```make``` command.
