//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "room/room";
#include "/room/clones.h"
void reset(int arg) {
    set_light(1);
    set_short("Castle Corridor");
    no_castle_flag = 1;
    set_long(
        "You are moving along a corridor in Saxon's castle.\n" +
        "The walls are made from thick blocks of granite.\n" +
        "");
    set_dest_dir(({
        "players/gor/castle/2", "east",
        "players/gor/castle/guard1", "west",
    }));
    add_clone("players/gor/monsters/guard", 1);
    ::reset();
    replace_program("room/room");
}
