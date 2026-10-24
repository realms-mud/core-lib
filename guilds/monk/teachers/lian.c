//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/realizations/researchTeacher.c";

/////////////////////////////////////////////////////////////////////////////
public string teachingGuild()
{
    return "monk";
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("lian");
    short("Sister Lian, instructor of foundations");
    description("Lian watches the training floor with patient attention. "
        "She welcomes prospective monks, teaches a small foundational "
        "curriculum, and recognizes students ready for further instruction.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("brawler", 15);
    addRelationshipInteraction("training.completed",
        ([ "respect":2, "admiration":1 ]));

    deferLessonLoading();
    addLesson("/guilds/monk/discipline/initiates-discipline.c", ([]), "");
    addLesson("/guilds/monk/discipline/steady-practice.c", ([
        "Lian's respect":([
            "type":"relationship",
            "direction":"from",
            "target":"owner",
            "dimension":"respect",
            "minimum":2
        ])
    ]), "Lian requires at least 2 respect for you. Complete her initial "
        "instruction to earn it; bows and gifts do not replace lessons.");
    addLesson("/guilds/monk/discipline/teachers-recognition.c", ([
        "Lian's respect":([
            "type":"relationship",
            "direction":"from",
            "target":"owner",
            "dimension":"respect",
            "minimum":4
        ])
    ]), "Lian requires at least 4 respect for you and completion of "
        "Steady Practice before granting recognition.");
    addLesson("/guilds/monk/unarmed/measured-palm.c", ([
        "Lian's respect":([
            "type":"relationship",
            "direction":"from",
            "target":"owner",
            "dimension":"respect",
            "minimum":2
        ])
    ]), "Lian requires at least 2 respect for you before teaching "
        "Measured Palm. Complete her initial instruction.");
    addLesson("/guilds/monk/unarmed/balanced-recovery.c", ([
        "Lian's respect":([
            "type":"relationship",
            "direction":"from",
            "target":"owner",
            "dimension":"respect",
            "minimum":4
        ])
    ]), "Lian requires at least 4 respect for you before teaching "
        "Balanced Recovery.");
    addLesson("/guilds/monk/katana/measured-cut.c", ([
        "Lian's respect":([
            "type":"relationship",
            "direction":"from",
            "target":"owner",
            "dimension":"respect",
            "minimum":2
        ])
    ]), "Lian requires at least 2 respect for you before teaching "
        "Measured Cut. Complete her initial instruction.");
    addLesson("/guilds/monk/katana/settled-edge.c", ([
        "Lian's respect":([
            "type":"relationship",
            "direction":"from",
            "target":"owner",
            "dimension":"respect",
            "minimum":4
        ])
    ]), "Lian requires at least 4 respect for you before teaching "
        "Settled Edge.");
}
