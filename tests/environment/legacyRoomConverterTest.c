//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
}

/////////////////////////////////////////////////////////////////////////////
void LegacyItemDisplaysCorrectDescription()
{
    object legacyRoom = clone_object("/lib/tests/support/environment/legacy/testLegacyEnvironment.c");
    object legacyItem = legacyRoom->getEnvironmentalElement("throne");
    ExpectEq("For being made out of gold, it really looks comfy.\n", legacyItem->long());

    destruct(legacyItem);
    destruct(legacyRoom);
}

/////////////////////////////////////////////////////////////////////////////
void CanTranslateSimpleLegacyRoomThatUsesSetupFunctions()
{
    object oldRoom = load_object("/lib/tests/support/environment/legacy/simpleLegacyUsingFunctions.c");
    ExpectEq("//*****************************************************************************\n"
        "// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See\n"
        "//                      the accompanying LICENSE file for details.\n"
        "//*****************************************************************************\n"
        "inherit \"/lib/environment/environment.c\";\n"
        "\n"
        "/////////////////////////////////////////////////////////////////////////////\n"
        "public void Setup()\n"
        "{\n"
        "    setTerrain(\"/lib/environment/terrain/legacy.c\");\n"
        "    setShortDescription(\"Castle Corridor\");\n"
        "    setAdditionalLongDescription(\n"
        "        \"You are moving along a corridor in Saxon's castle.\\n\"\n"
        "        \"The walls are made from thick blocks of granite.\\n\");\n"
        "\n"
        "    addExit(\"east\", \"/lib/legacy/gor/castle/2.c\");\n"
        "    addExit(\"west\", \"/lib/legacy/gor/castle/guard1.c\");\n"
        "\n"
        "    addObject(\"/lib/legacy/gor/monsters/guard.c\");\n"
        "}\n"
        "\n"
        "/////////////////////////////////////////////////////////////////////////////\n"
        "protected int alwaysLight()\n"
        "{\n"
        "    return 1;\n"
        "}\n\n", 
        oldRoom->generateNewRoom());
}

/////////////////////////////////////////////////////////////////////////////
void CanTranslateSimpleLegacyRoomThatUsesVariables()
{
    object oldRoom = load_object("/lib/tests/support/environment/legacy/simpleLegacyUsingVariables.c");
    ExpectEq("//*****************************************************************************\n"
        "// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See\n"
        "//                      the accompanying LICENSE file for details.\n"
        "//*****************************************************************************\n"
        "inherit \"/lib/environment/environment.c\";\n"
        "\n"
        "/////////////////////////////////////////////////////////////////////////////\n"
        "public void Setup()\n"
        "{\n"
        "    setTerrain(\"/lib/environment/terrain/legacy.c\");\n"
        "    setShortDescription(\"Throne\");\n"
        "    setAdditionalLongDescription(\n"
        "        \"You have entered the throne room of Turgon. The throne itself is\\n\"\n"
        "        \"made almost fully out of gold- obviously, this man has no shame.\\n\"\n"
        "        \"Standing beside the throne are two other lesser thrones. In these sit\\n\"\n"
        "        \"Idril, his daughter; and Tuor (the human), her husband.\\n\"\n"
        "        \"There are also several statues of the Valar standing about.\\n\");\n"
        "\n"
        "    addLegacyItem(\"throne\", \"For being made out of gold, it really looks comfy\");\n"
        "    addLegacyItem(\"statues\", \"You see statues of the nine valar\");\n"
        "\n"
        "    addExit(\"north\", \"/lib/legacy/maeglin/gondolin/tower12.c\");\n"
        "\n"
        "    addObject(\"/lib/tests/support/services/mockPlayer.c\");\n"
        "    addObject(\"/lib/instances/items/weapons/swords/long-sword.c\");\n"
        "    addObject(\"/lib/tests/support/services/mockNPC.c\");\n"
        "}\n"
        "\n"
        "/////////////////////////////////////////////////////////////////////////////\n"
        "protected int alwaysLight()\n"
        "{\n"
        "    return 1;\n"
        "}\n\n",
        oldRoom->generateNewRoom());
}

/////////////////////////////////////////////////////////////////////////////
void CanTranslateExtraMethods()
{
    object oldRoom = load_object("/lib/tests/support/environment/legacy/complexWithIncludesAndOldPlayerMethods.c");
    ExpectEq("//*****************************************************************************\n"
        "// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See\n"
        "//                      the accompanying LICENSE file for details.\n"
        "//*****************************************************************************\n"
        "inherit \"/lib/environment/environment.c\";\n"
        "\n"
        "/////////////////////////////////////////////////////////////////////////////\n"
        "public void Setup()\n"
        "{\n"
        "    setTerrain(\"/lib/environment/terrain/legacy.c\");\n"
        "    setShortDescription(\"Anfauglith, north path\");\n"
        "    setAdditionalLongDescription(\n"
        "        \"This area is thick with vegetation. There are many trees of\\n\"\n"
        "        \"all varieties standing about. All around you, the jagged peaks of\\n\"\n"
        "        \"the Echoriath jut up. To the south, you see a cliff - obviously, only\\n\"\n"
        "        \"a fool would actually try to climb down it here.\\n\");\n"
        "\n"
        "    addLegacyItem(\"cliff\", \"The cliff is much too treacherous to climb on\");\n"
        "    addLegacyItem(\"peaks\", \"They look like fairly typical mountain peaks\");\n"
        "    addLegacyItem(\"trees\", \"Lots of trees... admire them\");\n"
        "\n"
        "    addExit(\"north\", \"/lib/legacy/maeglin/anfauglith/anf3.c\");\n"
        "    addExit(\"west\", \"/lib/legacy/maeglin/anfauglith/echoriath2.c\");\n"
        "    addExit(\"east\", \"/lib/legacy/maeglin/anfauglith/echoriath4.c\");\n"
        "\n"
        "    addObject(\"/lib/tests/support/services/mockNPC.c\");\n"
        "}\n"
        "\n"
        "/////////////////////////////////////////////////////////////////////////////\n"
        "protected int alwaysLight()\n"
        "{\n"
        "    return 1;\n"
        "}\n"
        "\n"
        "/////////////////////////////////////////////////////////////////////////////\n"
        "void init() {\n"
        "  ::init();\n"
        "  add_action(\"climb\", \"climb\");\n"
        "  add_action(\"kill_me\", \"kill\");\n"
        "  add_action(\"look\", \"look\");\n"
        "  add_action(\"look\", \"l\");\n"
        "  add_action(\"look\", \"exa\");\n"
        "}\n"
        "\n"
        "int look(string str) {\n"
        "  if (str == \"at thing\" || str == \"at nasty icky thing\" || str == \"thing\" ||\n"
        "    str == \"nasty icky thing\") {\n"
        "    write(\"A nasty icky thing with fetid breath.\\nThing isn't even phased.\\n\"+\n"
        "      \"        Thing is carrying:\\n\"+this_player()->Name()+\n"
        "      \"'s arm (wielded).\\nBonebanded mail (worn).\\n\");\n"
        "    return 1;\n"
        "  }\n"
        "}\n"
        "\n"
        "int kill_me() {\n"
        "  tell_room(environment(this_player()), \"The Nasty Icky thing growls, \"+\n"
        "    \"wafting its fetid breath on you.\\n\"+\n"
        "    \"It grabs hold of \"+this_player()->Name()+\" and picks \"+\n"
        "    this_player()->Objective()+\" up.\\n\"+\n"
        "    \"It throws \"+this_player()->Objective()+\" over the cliff!\\n\"+\n"
        "    this_player()->Name()+\" screams in terror!\\n\");\n"
        "  call_out(\"thud\", 2);\n"
        "  return 1;\n"
        "}\n"
        "\n"
        "int thud() {\n"
        "  say(\"You hear a faint 'thud' as \"+this_player()->Name()+\n"
        "    \" splats to the ground below.\\n\");\n"
        "  move_object(this_player(),\"/lib/legacy/maeglin/gondolin/drybed1\");\n"
        "\n"
        "  say(this_player()->Name()+\" lands with a sickening 'THUD'.\\n\");\n"
        "  write(\"You land with a sickening 'THUD'.\\n\");\n"
        "  write(\"You feel very disoriented.\\n\");\n"
        "  this_player()->hit(this_player()->hitPoints()*2/3);\n"
        "  move_object(clone_object(\"/lib/legacy/maeglin/items/stun\"), this_player());\n"
        "  return 1;\n"
        "}\n\n"
        "int climb() {\n"
        "  write(\"If you tried that here, the nasty icky thing would do mean things \"+\n"
        "    \"to you.\\n\");\n"
        "  return 1;\n"
        "}\n",
        oldRoom->generateNewRoom());
}

/////////////////////////////////////////////////////////////////////////////
void CanTranslateIncludedFiles()
{
    object oldRoom = load_object("/lib/tests/support/environment/legacy/complexWithIncludeContainingMethods.c");
    ExpectEq("//*****************************************************************************\n"
        "// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See\n"
        "//                      the accompanying LICENSE file for details.\n"
        "//*****************************************************************************\n"
        "inherit \"/lib/environment/environment.c\";\n"
        "\n"
        "/////////////////////////////////////////////////////////////////////////////\n"
        "public void Setup()\n"
        "{\n"
        "    setTerrain(\"/lib/environment/terrain/legacy.c\");\n"
        "    setShortDescription(\"The river Sirion\");\n"
        "    setAdditionalLongDescription(\n"
        "        \"You wander down the banks of the river Sirion. You begin to wonder\\n\"\n"
        "        \"if you'll ever find the fabled city of Gondolin.\\n\"\n"
        "        \"To the west, you can spot one of the fords of Sirion.\\n\");\n"
        "\n"
        "    addLegacyItem(\"banks\", \"The banks are low enough to allow you to ford the river here\");\n"
        "    addLegacyItem(\"city\", \"Nope... sorry. No city here\");\n"
        "    addLegacyItem(\"gondolin\", \"You wish\");\n"
        "    addLegacyItem(\"ford\", \"A treacherous yet passable ford\");\n"
        "\n"
        "    addExit(\"north\", \"/lib/legacy/maeglin/anfauglith/anfe7.c\");\n"
        "    addExit(\"south\", \"/lib/legacy/maeglin/anfauglith/anfe9.c\");\n"
        "    addExit(\"west\", \"/lib/legacy/maeglin/anfauglith/sirion_ford.c\");\n"
        "\n"
        "}\n"
        "\n"
        "/////////////////////////////////////////////////////////////////////////////\n"
        "protected int alwaysLight()\n"
        "{\n"
        "    return 1;\n"
        "}\n"
        "\n"
        "/////////////////////////////////////////////////////////////////////////////\n"
        "void init() {\n"
        "  ::init();\n"
        "  add_action(\"search\", \"search\");\n"
        "}\n"
        "\n"
        "object critter;\n"
        "#define TP this_player()\n"
        "#define TN this_player()->Name()\n"
        "\n"
        "int search() {\n"
        "  switch(random(9)) {\n"
        "    case 1: return \n"
        "      printf(\"You search around for a while and get incredibly bored.\\n\"),1;\n"
        "    case 2: return\n"
        "      printf(\"You dejectedly search the ground, finding nothing.\\n\"),1;\n"
        "    case 3:\n"
        "      tell_room(environment(TP), sprintf(\"%s spots an ant peacefully \"\n"
        "        \"crawling along doing ant things.\\n%s screams, `LOOK!!! NATURE!'\\n\"\n"
        "        \"%s maliciously steps on it, laughing hysterically.\\n\", TN, TN,\n"
        "        capitalize(TP->Pronoun())));\n"
        "      printf(\"You find nothing else of interest and sadly move along.\\n\");\n"
        "      return 1;\n"
        "    case 4:\n"
        "      return printf(\"You spot a rather interesting clod of dirt.\\n\"\n"
        "        \"Sadly, as you go to pick it up, it breaks.\\n\"),1;\n"
        "    case 5: return\n"
        "      printf(\"You look around. You find nothing. You grumble and move on.\\n\"),1;\n"
        "    case 6: return\n"
        "      printf(\"You look around but find nothing to alter the monotony.\\n\"),1;\n"
        "    case 7:\n"
        "      return printf(\"You moan in despair as you find nothing of value.\\n\"),1;\n"
        "    case 8:\n"
        "      return printf(\"You stomp on several small shrubs but this doesn't help \"\n"
        "        \"you find anything.\\n\"),1;\n"
        "    default:\n"
        "      if (!critter) {\n"
        "        printf(\"You search for a while and discover that you are not alone.\\n\");\n"
        "        critter = clone_object(\"/lib/tests/support/services/mockNPC.c\");\n"
        "        critter->generate(TP->effectiveLevel());\n"
        "        move_object(critter, environment(this_player()));\n"
        "        return 1;\n"
        "      }\n"
        "      printf(\"You find little but boredom and despair.\\n\");\n"
        "      return 1;\n"
        "  }\n"
        "  return 1;\n"
        "}\n",
        oldRoom->generateNewRoom());
}
