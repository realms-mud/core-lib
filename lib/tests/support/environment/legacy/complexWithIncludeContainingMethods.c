//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "room/room";
#include "/lib/tests/support/environment/legacy/includeWithMethods.c"

void reset(int arg) {
  if (arg) return;

  items = ({
    "banks", "The banks are low enough to allow you to ford the river here",
    "city", "Nope... sorry. No city here",
    "gondolin", "You wish",
    "ford", "A treacherous yet passable ford",
  });
  set_light(1);
  no_castle_flag = 0;
  short_desc = "The river Sirion";
  long_desc =
  "You wander down the banks of the river Sirion. You begin to wonder\n" +
  "if you'll ever find the fabled city of Gondolin.\n"+
  "To the west, you can spot one of the fords of Sirion.\n";
  dest_dir = ({
    "/players/maeglin/anfauglith/anfe7", "north",
    "/players/maeglin/anfauglith/anfe9", "south",
    "/players/maeglin/anfauglith/sirion_ford", "west",
  });
}

void init() {
  ::init();
  add_action("search", "search");
}
