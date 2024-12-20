//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "room/room";
#include "/include/resist.h" //Damage types for all! 4/12/02 -Caleb

void reset(int arg) {
  if (arg) return;

  items = ({ 
    "cliff", "The cliff is much too treacherous to climb on",
    "peaks", "They look like fairly typical mountain peaks",
    "trees", "Lots of trees... admire them",
  });
  set_light(1);
  no_castle_flag = 0;
  move_object(clone_object("/lib/tests/support/services/mockNPC.c"), this_object());
  short_desc = "Anfauglith, north path";
  long_desc =
    "This area is thick with vegetation. There are many trees of\n"+
    "all varieties standing about. All around you, the jagged peaks of\n"+
    "the Echoriath jut up. To the south, you see a cliff - obviously, only\n"+
    "a fool would actually try to climb down it here.\n";
  dest_dir = ({
    "/players/maeglin/anfauglith/anf3", "north",
    "/players/maeglin/anfauglith/echoriath2", "west",
    "/players/maeglin/anfauglith/echoriath4", "east",
  });
}

void init() {
  ::init();
  add_action("climb", "climb");
  add_action("kill_me", "kill");
  add_action("look", "look");
  add_action("look", "l");
  add_action("look", "exa");
}

int look(string str) {
  if (str == "at thing" || str == "at nasty icky thing" || str == "thing" ||
    str == "nasty icky thing") {
    write("A nasty icky thing with fetid breath.\nThing isn't even phased.\n"+
      "        Thing is carrying:\n"+this_player()->query_name()+
      "'s arm (wielded).\nBonebanded mail (worn).\n");
    return 1;
  }
  return 0;
}

int kill_me() {
  tell_room(environment(this_player()), "The Nasty Icky thing growls, "+
    "wafting its fetid breath on you.\n"+
    "It grabs hold of "+this_player()->query_name()+" and picks "+
    this_player()->query_objective()+" up.\n"+
    "It throws "+this_player()->query_objective()+" over the cliff!\n"+
    this_player()->query_name()+" screams in terror!\n");
  call_out("thud", 2);
  return 1;
}

int thud() {
  say("You hear a faint 'thud' as "+this_player()->query_name()+
    " splats to the ground below.\n");
  move_object(this_player(),"/players/maeglin/gondolin/drybed1");

  say(this_player()->query_name()+" lands with a sickening 'THUD'.\n");
  write("You land with a sickening 'THUD'.\n");
  write("You feel very disoriented.\n");
  this_player()->hit_player(this_player()->query_hp()*2/3, DAMAGE_PHYSICAL);
  move_object(clone_object("/players/maeglin/items/stun"), this_player());
  return 1;
}

int climb() {
  write("If you tried that here, the nasty icky thing would do mean things "+
    "to you.\n");
  return 1;
}
