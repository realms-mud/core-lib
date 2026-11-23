//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/realizations/researchTeacher.c";

/////////////////////////////////////////////////////////////////////////////
public string teachingGuild()
{
    return "Aegis Guard";
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Lethar");
    short("Sergeant Lethar, Aegis recruiter and instructor");
    description("Lethar keeps the Aegis Guard's enrollment and training "
        "records. He expects discipline before ambition.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("city guard", 15);

    foreach (string tree in ({
        "sword-attacks", "sword-evading", "sword-guarding", "bows",
        "sword-combinations", "sword-actions", "sword-elemental",
        "sword-mythic"
    }))
    {
        addLessonTree("/guilds/aegis-guard/" + tree + ".c", ({}));
    }

    addConversation(
        "/areas/eledhel/central-city/characters/aegis-recruiterConversation.c");
}
