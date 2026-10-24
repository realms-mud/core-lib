//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/realizations/researchTeacher.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("iori");
    short("Brother Iori, instructor of the measured bow");
    description("Iori tests the tension of a practice bow before each "
        "lesson. He teaches recognized monks to balance patient releases "
        "against the stamina, ammunition, and exposure each shot costs.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("archer", 30);
    addRelationshipInteraction("training.completed",
        ([ "respect":2, "admiration":1 ]));
    deferLessonLoading();
    addLessonTree("/guilds/monk/archery.c", ({}));
}
