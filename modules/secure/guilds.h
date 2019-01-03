//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping guilds = ([]);
private int unassignedExperience;

/////////////////////////////////////////////////////////////////////////////
static nomask void loadGuilds(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence))
    {
        unassignedExperience = persistence->extractSaveData("unassignedExperience", data);

        guilds = persistence->extractSavedMapping("guilds", data);

        if (sizeof(guilds))
        {
            string *guildList = m_indices(guilds);
            foreach(string guild in guildList)
            {
                if (member(guilds[guild], "left guild") &&
                    !guilds[guild]["left guild"])
                {
                    m_delete(guilds[guild], "left guild");
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask mapping sendGuilds()
{
    mapping ret = ([
        "guilds": ([]),
        "unassignedExperience": unassignedExperience
    ]);

    string *guildList = m_indices(guilds);
    foreach(string guild in guildList)
    {
        string *keys = m_indices(guilds[guild]);
        if (sizeof(keys))
        {
            ret["guilds"][guild] = ([]);

            foreach(string key in keys)
            {
                ret["guilds"][guild][key] = guilds[guild][key];
            }
        }
    }
    return ret;
}
