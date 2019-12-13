//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "room/room";

object monster;
void reset(int arg) {
  if (!present("elf", this_object())) {
    monster = clone_object("/lib/tests/support/services/mockNPC.c");
    move_object(monster, this_object());
    monster = clone_object("/lib/tests/support/services/mockPlayer.c");
    move_object(monster, this_object());
    monster = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    move_object(monster, this_object());
  }
  items = ({
    "throne", "For being made out of gold, it really looks comfy",
    "statues", "You see statues of the nine valar",
  });
  set_light(1);
  no_castle_flag = 0;
  short_desc = "Throne";
  long_desc =
    "You have entered the throne room of Turgon. The throne itself is\n"+
    "made almost fully out of gold- obviously, this man has no shame.\n"+
    "Standing beside the throne are two other lesser thrones. In these sit\n"+
    "Idril, his daughter; and Tuor (the human), her husband.\n"+
    "There are also several statues of the Valar standing about.\n";
  dest_dir = ({
    "/players/maeglin/gondolin/tower12", "north",
  });
}
