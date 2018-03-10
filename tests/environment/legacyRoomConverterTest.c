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
        "    addExit(\"east\", \"/lib/legacy/gor/castle/2\");\n"
        "    addExit(\"west\", \"/lib/legacy/gor/castle/guard1\");\n"
        "\n"
        "    addObject(\"/lib/legacy/gor/monsters/guard\");\n"
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
"    addExit(\"north\", \"/lib/legacy/maeglin/gondolin/tower12\");\n"
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
