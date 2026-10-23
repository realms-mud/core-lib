//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/realizations/researchTeacher.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("ren");
    short("Brother Ren, instructor of deliberate movement");
    description("Ren demonstrates slow, economical staff movements and "
        "the controlled projection of internal energy. "
        "He offers advanced instruction to monks who arrive with "
        "a foundation instructor's recognition, not to every visitor.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("staff man", 25);
    addRelationshipInteraction("training.completed",
        ([ "respect":2, "admiration":1 ]));
    addLesson("/guilds/monk/discipline/controlled-expenditure.c", ([]), "");
    addLesson("/guilds/monk/pure-chi/focused-pulse.c", ([]), "");
    addLesson("/guilds/monk/mana-shield/mindful-ward.c", ([]), "");
    addLesson("/guilds/monk/bludgeon/measured-impact.c", ([]), "");
    addLesson("/guilds/monk/bludgeon/settled-guard.c", ([]), "");
    addLesson("/guilds/monk/discipline/adepts-trial.c", ([]), "");
    addLesson("/guilds/monk/discipline/senior-disciples-trial.c", ([]), "");
    addLesson("/guilds/monk/discipline/master-candidates-trial.c", ([]), "");
    addLesson("/guilds/monk/discipline/masters-trial.c", ([]), "");
    string *lianLessons = ({
        "/guilds/monk/unarmed/measured-palm.c",
        "/guilds/monk/unarmed/balanced-recovery.c",
        "/guilds/monk/katana/measured-cut.c",
        "/guilds/monk/katana/settled-edge.c"
    });
    foreach(string treePath in ({
        "/guilds/monk/unarmed.c",
        "/guilds/monk/katana.c",
        "/guilds/monk/bludgeon.c",
        "/guilds/monk/pure-chi.c",
        "/guilds/monk/mana-shield.c"
    }))
    {
        object tree = getService("research")->researchTree(treePath);
        foreach(object item in m_indices(tree->getFlattenedResearchTree()))
        {
            string path = program_name(item);
            if (item->query("research type") != "tree root" &&
                member(lianLessons, path) < 0 && !teachesResearch(path))
            {
                addLesson(path, ([]), "");
            }
        }
    }
}
