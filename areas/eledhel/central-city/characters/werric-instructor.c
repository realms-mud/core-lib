//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/realizations/researchTeacher.c";

/////////////////////////////////////////////////////////////////////////////
public string teachingGuild()
{
    return "Werric Knight";
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Caldrin");
    short("Sir Caldrin, a Werric Knight instructor");
    description("Caldrin studies the old records before leading "
        "instruction in the great hall.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("swordsman", 15);

    foreach (string tree in ({
        "sword-mastery", "shield-mastery", "oath-bound", "light-magic",
        "defensive-tactics", "discipline", "unbroken-will",
        "elven-martial-arts", "mounted-combat", "tactical-warfare",
        "knightly-virtues", "defender-of-crown", "lord-marshal"
    }))
    {
        addLessonTree("/guilds/werric-knight/" + tree + ".c", ({}));
    }

    addConversation(
        "/areas/eledhel/central-city/characters/werric-instructorConversation.c");
}
