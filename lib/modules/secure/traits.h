//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef traitsModule_h
#define traitsModule_h

private mapping traits = ([]);
private string *temporaryTraits = ({});

/////////////////////////////////////////////////////////////////////////////
static nomask void loadTraits(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence))
    {
        traits = persistence->extractSavedMapping("traits", data);
        string *traitList = m_indices(traits);
        if (sizeof(traitList))
        {
            object traitsService = getService("traits");
            foreach(string trait in traitList)
            {
                string *bonuses = traitsService->getTraitBonuses(trait);
                if (bonuses && sizeof(bonuses))
                {
                    traits[trait]["bonuses"] = bonuses;
                }
            }
        }
        string temporaryTraitsString = 
            persistence->extractSaveData("temporaryTraits", data);

        if (stringp(temporaryTraitsString))
        {
            temporaryTraits = explode(temporaryTraitsString, "##") - ({ "" });
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask mapping sendTraits()
{
    mapping ret = ([
        "traits":([]),
        "temporaryTraits": implode(m_indices(mkmapping(temporaryTraits)), "##")
    ]);

    string *list = filter(m_indices(traits),
        (: (member(temporaryTraits, $1) < 0) :));

    foreach(string trait in list)
    {
        string *keys = m_indices(traits[trait]);
        if (sizeof(keys))
        {
            ret["traits"][trait] = ([]);

            foreach(string key in keys)
            {
                ret["traits"][trait][key] = traits[trait][key];
            }
        }
    }
    return ret;
}

#endif
