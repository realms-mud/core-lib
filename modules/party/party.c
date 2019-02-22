//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private string Name;
private object Creator;
private mapping Members = ([]);
private int TotalWeight = 0;
private object Dictionary = load_object("/lib/dictionaries/partyDictionary.c");

/////////////////////////////////////////////////////////////////////////////
public nomask string partyName()
{
    return Name;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object creator()
{
    return Creator;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object *members()
{
    return m_indices(Members);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void refresh()
{
    object *memberList = members();
    if (sizeof(memberList))
    {
        TotalWeight = 0;
        foreach(object person in memberList)
        {
            int newLevel = person->effectiveLevel();
            Members[person] = newLevel;
            TotalWeight += newLevel;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addMember(object newMember)
{
    Members[newMember] = 1;
    refresh();
}

/////////////////////////////////////////////////////////////////////////////
public nomask void createParty(string name, object creator)
{
    if (stringp(name) && objectp(creator) &&
        (member(inherit_list(creator), "lib/realizations/player.c") > -1))
    {
        Name = sprintf("%s#%s", name, creator->RealName());
        Creator = creator;
        addMember(creator);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void joinParty(object newMember)
{
    if (Dictionary->joinParty(this_object(), newMember))
    {
        addMember(newMember);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void leaveParty(object member)
{
    if (Dictionary->leaveParty(this_object(), member))
    {
        m_delete(Members, member);
        refresh();
    }

    if (!sizeof(Members))
    {
        Dictionary->dissolveParty(this_object());
    }
    else if (member == Creator)
    {
        Creator = m_indices(Members)[0];
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void dissolveParty()
{
    Dictionary->dissolveParty(this_object());
}

/////////////////////////////////////////////////////////////////////////////
private nomask int experienceEarned(int amount, object person)
{
    float percentageEarned = (1.0 * Members[person]) / TotalWeight;
    int ret = to_int(amount * percentageEarned);
    if (ret < 1)
    {
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void pruneMissingPlayers()
{
    object *memberList = members();
    string *cachedMembers = Dictionary->getPartyMembers(this_object());

    if (sizeof(memberList))
    {
        foreach(object person in memberList)
        {
            cachedMembers -= ({ person->RealName() });
        }
    }

    if (sizeof(cachedMembers))
    {
        foreach(string person in cachedMembers)
        {
            Dictionary->leavePartyByName(this_object(), person);
        }

        if (!objectp(Creator) && sizeof(Members))
        {
            Creator = m_indices(Members)[0];
        }
        refresh();
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int reallocateExperience(int amount, string selectedGuild,
    object initiator)
{
    int ret = amount;

    pruneMissingPlayers();
    
    object *memberList = members();
    if (sizeof(memberList))
    {
        foreach(object person in memberList)
        {
            if (person == initiator)
            {
                ret = experienceEarned(amount, person);
            }
            else
            {
                person->addExperience(experienceEarned(amount, person), 
                    selectedGuild, 1);
            }
        }
    }
    else
    {
        dissolveParty();
    }
    return ret;
}
