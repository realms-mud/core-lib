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
