//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private mapping channelRegistry = ([]);
private object Configuration;

/////////////////////////////////////////////////////////////////////////////
private nomask object configuration()
{
    if (!Configuration)
    {
        Configuration = getService("configuration");
    }
    return Configuration;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void registerChannel(string channelName)
{
    if (!member(channelRegistry, channelName))
    {
        channelRegistry[channelName] = ({});
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void unregisterChannel(string channelName)
{
    if (member(channelRegistry, channelName))
    {
        m_delete(channelRegistry, channelName);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void broadcastMessage(string channelName, string message, 
    object sender)
{
    if (member(channelRegistry, channelName) && 
        sizeof(channelRegistry[channelName]))
    {
        foreach(object user in channelRegistry[channelName])
        {
            if (objectp(user) && !user->blocked(sender))
            {
                string channelDisplay = regreplace(channelName, 
                    "([^#]*).*", "\\1", 1);

                string headerText = sprintf("[ %s %s ]: ", capitalize(channelDisplay),
                    ((channelName == "status") ? "" : capitalize(sender->RealName())));

                string header = configuration()->decorate(
                    sprintf("[ %s %s ]: ", capitalize(channelDisplay),
                        ((channelName == "status") ? "" : capitalize(sender->RealName()))),
                    "header", "channel", user->colorConfiguration());

                string body = explode(format(headerText + message, 78), headerText)[1];
                body = configuration()->decorate(body, "body", "channel", 
                    user->colorConfiguration());
                user->receiveMessage(header + body);
            }
            else if(!objectp(user))
            {
                channelRegistry[channelName] -= ({ user });
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *getWizardChannels(object user)
{
    string *ret = ({});
    if (member(inherit_list(user), "/lib/realizations/wizard.c") > -1)
    {
        ret += ({ "wiz", "status", "issue logged by" });

        if (member(({ "owner", "god", "demigod", "archwizard", "sage", "elder" }),
            user->wizardLevel()) > -1)
        {
            ret += ({ "hiz" });
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *getGuildChannels(object user)
{
    string *guilds = user->memberOfGuilds();
    if (!sizeof(guilds))
    {
        guilds += ({ "guildless" });
    }
    return guilds;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *getRaceChannel(object user)
{
    string *ret = ({});
    if (user->Race())
    {
        ret += ({ user->Race() });
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *getFactionChannels(object user)
{
    return ({});
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *getPartyChannel(object user)
{
    string *ret = ({});

    object party = user->getParty();
    if (party)
    {
        ret += ({ party->partyName() });
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *getChannelsForUser(object user)
{
    return getWizardChannels(user) +
        getGuildChannels(user) +
        getRaceChannel(user) +
        getPartyChannel(user) +
        getFactionChannels(user);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void registerUser(object user)
{
    string *channels = getChannelsForUser(user);

    if (sizeof(channels))
    {
        foreach(string channel in channels)
        {
            if (!member(channelRegistry, channel))
            {
                registerChannel(channel);
            }

            if (member(channelRegistry[channel], user) < 0)
            {
                channelRegistry[channel] += ({ user });
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void unregisterUser(object user)
{
    string *channels = getChannelsForUser(user);

    if (sizeof(channels))
    {
        foreach(string channel in channels)
        {
            if (sizeof(channelRegistry[channel]))
            {
                channelRegistry[channel] -= ({ user });
            }
            if (!sizeof(channelRegistry[channel]))
            {
                unregisterChannel(channel);
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void unregisterUserFromPartyChannel(object user)
{
    string *channels = getPartyChannel(user);

    if (sizeof(channels))
    {
        foreach(string channel in channels)
        {
            if (sizeof(channelRegistry[channel]))
            {
                channelRegistry[channel] -= ({ user });
            }
            if (!sizeof(channelRegistry[channel]))
            {
                unregisterChannel(channel);
            }
        }
    }
}
