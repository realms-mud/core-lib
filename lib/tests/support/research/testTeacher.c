//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/realizations/researchTeacher.c";

protected void Setup()
{
    Name("instructor");
    addLesson("/lib/tests/support/research/teacherRequiredPointsResearch.c",
        ([]), "");
    addLesson("/lib/tests/support/research/teacherRequiredTimedResearch.c",
        ([]), "");
}
