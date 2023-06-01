# so_long
First graphical project

So long is one of 42 common core's projects which gives you the basics in the following skills:
- window management
- event management
- choice of colors and textures.

It uses the MLX 42 library which includes basic tools to open a window, to create images and to manage keyboard and mouse events.

## How does my So_long works ?

My ***So_long*** has two versions:

The first being the very basic So_long without any animation. You still have to collect all the collectibles to be able to exit the game successfully.

The second version is my **_bonus version_** where it includes enemie(s) which only move(s) from LEFT to RIGHT. If you end up crossing paths with an enemy, you will lose !

![so_long](https://github.com/hanmpark/so_long/blob/master/github_so_long.gif)

### My Makefile rules

```bash
  make all
```
- It compiles the simple game

```bash
  make bonus
```
- It compiles the bonus part

```bash
  make rebonus
```
- It _fclean_ and compiles the bonus part

```bash
  make norminette
```
- It checks the norm for every files in a pretty way

```bash
  make test
```
- It checks the parsing (more useful during the defense)

### How to start my So_long
After having compiled the program simply type the following command and put the path to your desired map
```bash
  ./so_long _PATH_TO_MAP_
```
