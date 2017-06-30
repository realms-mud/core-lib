//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private mapping traits = ([]);
private string *temporaryTraits = ({});

/////////////////////////////////////////////////////////////////////////////
static nomask void loadTraits(mapping data, object persistence)
{
    write("oink!\n");
    if (isValidPersistenceObject(persistence))
    {
        traits = persistence->extractSavedMapping("traits", data);        
        temporaryTraits = explode(
            persistence->extractSaveData("temporaryTraits", data), "##") - ({ "" });
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask mapping sendTraits()
{
    mapping ret = ([
        "traits":([]),
        "temporaryTraits": implode(temporaryTraits, "##")
    ]);

    string *list = m_indices(traits);
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