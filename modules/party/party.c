//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private string Name;
private object Creator;
private mapping Members = ([]);
private int TotalWeight = 0;
private object Dictionary = load_object("/lib/dictionaries/partyDictionary.c");
private object channels = load_object("/lib/dictionaries/channelDictionary.c");
private object configuration = 
    load_object("/lib/dictionaries/configurationDictionary.c");
private object commands =
    load_object("/lib/dictionaries/commandsDictionary.c");

private mapping information = ([
    "experience earned": ([]),
    "best kill": ([]),
    "following": ([]),
]);

/////////////////////////////////////////////////////////////////////////////
public nomask string partyName()
{
    return Name;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string RealName()
{
    return "Info";
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
    information["experience earned"][newMember->RealName()] = 0;
    refresh();
}

/////////////////////////////////////////////////////////////////////////////
public nomask void createParty(string name, object creator)
{
    if (stringp(name) && objectp(creator) &&
        (member(inherit_list(creator), "lib/realizations/player.c") > -1))
    {
        if (sizeof(name) < 40)
        {
            Name = sprintf("%s#%s", name, creator->RealName());
            Creator = creator;
            addMember(creator);
            channels->registerChannel(Name);
            channels->registerUser(creator);
        }
        else
        {
            tell_object(creator, "You're naming a party, not writing a book.\n"
                "Pick a name that's no longer than 40 characters.\n");
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void joinParty(object newMember)
{
    if (Dictionary->joinParty(this_object(), newMember))
    {
        addMember(newMember);
        channels->registerUser(newMember);

        channels->broadcastMessage(partyName(),
            sprintf("%s has joined the party.",
                capitalize(newMember->RealName())), this_object());
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void leaveParty(object member)
{
    if (Dictionary->leaveParty(this_object(), member))
    {
        m_delete(Members, member);

        channels->unregisterUserFromPartyChannel(member);

        channels->broadcastMessage(partyName(),
            sprintf("%s has left the party.",
                capitalize(member->RealName())), this_object());
        refresh();
    }

    if (!sizeof(Members))
    {
        Dictionary->dissolveParty(this_object());
        channels->unregisterChannel(Name);
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
    channels->unregisterChannel(Name);
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

    information["experience earned"][person->RealName()] += ret;
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

/////////////////////////////////////////////////////////////////////////////
private nomask string memberBanner(string colorConfiguration, string charset)
{
    return commands->buildBanner(colorConfiguration, charset,
        "top", sprintf("Members of '%s' Party",
            regreplace(partyName(), "(#.*)", "", 1))) +
        commands->banneredContent(colorConfiguration, charset,
            configuration->decorate(sprintf("%-18s ", "Name"),
                "heading", "party", colorConfiguration) +
            commands->divider(colorConfiguration, charset) +
            configuration->decorate(sprintf(" %-18s ", "Location"),
                "heading", "party", colorConfiguration) +
            commands->divider(colorConfiguration, charset) +
            configuration->decorate(sprintf(" %-18s ", "Following"),
                "heading", "party", colorConfiguration) +
            commands->divider(colorConfiguration, charset) +
            configuration->decorate(sprintf(" %-11s ", "Exp Earned"),
                "heading", "party", colorConfiguration)) +
        commands->buildBanner(colorConfiguration, charset,
            "middle", "", "", 1);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getMemberInformation(string colorConfiguration,
    string charset, object initiator)
{
    string ret = memberBanner(colorConfiguration, charset);

    object *currentMembers = members();
    string *memberList = m_indices(information["experience earned"]);
    if (sizeof(memberList))
    {
        memberList = sort_array(memberList,
            (: information["experience earned"][$1] <
                information["experience earned"][$2] :));
    }

    foreach(string member in memberList)
    {
        object *memberObj = filter(currentMembers,
            (: $1->RealName() == $2 :), member);

        string location = "No longer in party";
        string displayColor = "former member";

        if (sizeof(memberObj))
        {
            displayColor = (memberObj[0] == Creator) ? "creator" :
                "active member";

            location = "Nowhere";
            object memberLocation = environment(memberObj[0]);
            if (memberLocation)
            {
                location = memberLocation->short() || "Unknown";

                if (sizeof(location) > 18)
                {
                    location = location[0..14] + "...";
                }
            }
        }

        ret += commands->banneredContent(colorConfiguration, charset,
            configuration->decorate(sprintf("%-18s ",
                capitalize(member)),
                displayColor, "party", colorConfiguration) +
            commands->divider(colorConfiguration, charset) +
            configuration->decorate(sprintf(" %-18s ", location),
                "data", "party", colorConfiguration) +
            commands->divider(colorConfiguration, charset) +
            configuration->decorate(sprintf(" %-18s ",
                (sizeof(memberObj) && member(information["following"], memberObj[0]) ?
                capitalize(information["following"][memberObj[0]]->RealName()) :
                "Nobody")),
                "data", "party", colorConfiguration) +
            commands->divider(colorConfiguration, charset) +
            configuration->decorate(sprintf(" %11d ",
                (member(information["experience earned"], member) ?
                information["experience earned"][member] : 0)),
                "data", "party", colorConfiguration)
        );
    }

    ret += commands->buildBanner(colorConfiguration, charset,
        "bottom", "", "", 1);
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string partyStatistics(object initiator)
{
    string ret = "";

    if (objectp(initiator) && initiator->isRealizationOfPlayer())
    {
        string colorConfiguration = initiator->colorConfiguration();
        string charset = initiator->charsetConfiguration();

        ret += getMemberInformation(colorConfiguration, charset, initiator);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string following(object initiator)
{
    string ret = 0;

    object *potentialLeaders = m_indices(information["following"]);
    if (sizeof(potentialLeaders))
    {
        foreach(object leader in potentialLeaders)
        {
            if (member(information["following"][leader], initiator) > -1)
            {
                ret = capitalize(leader->RealName());
                break;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void follow(object leader, object follower)
{
    if (!member(information["following"], leader))
    {
        information["following"][leader] = ({ follower });
    }
    else if(member(information["following"][leader], follower) < 0)
    {
        information["following"][leader] += ({ follower });
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string stopFollowing(object follower)
{
    string ret = 0;

    object *potentialLeaders = m_indices(information["following"]);
    if (sizeof(potentialLeaders))
    {
        foreach(object leader in potentialLeaders)
        {
            if (member(information["following"][leader], follower) > -1)
            {
                information["following"][leader] -= ({ follower });
                ret = capitalize(leader->RealName());
                break;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void moveFollowers(object leader, string destination,
    string direction, int silently, object region)
{
    if (member(information["following"], leader) > -1)
    {
        foreach(object follower in information["following"][leader])
        {
            follower->move(destination, direction, silently, region);
        }
    }
}
