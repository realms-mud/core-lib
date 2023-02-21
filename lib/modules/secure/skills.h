//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef skillsModule_h
#define skillsModule_h

private int availableSkillPoints;
private mapping skills = ([]);

/////////////////////////////////////////////////////////////////////////////
static nomask void loadSkills(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence))
    {
        availableSkillPoints = persistence->extractSaveData("availableSkillPoints", data);

        skills = ([]);
        if (member(data, "skills") && sizeof(data["skills"]))
        {
            string *list = m_indices(data["skills"]);
            foreach(string skill in list)
            {
                skills[skill] = data["skills"][skill];
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask mapping sendSkills()
{
    mapping ret = ([
        "skills":([]),
        "availableSkillPoints": availableSkillPoints
    ]);

    string *list = m_indices(skills);
    foreach(string skill in list)
    {
        ret["skills"][skill] = skills[skill];
    }
    return ret;
}

#endif
