//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private mapping channelRegistry = ([]);
private object Configuration;

/////////////////////////////////////////////////////////////////////////////
private nomask object configuration()
{
    if (!Configuration)
    {
        Configuration = load_object("/lib/dictionaries/configurationDictionary.c");
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
            if (objectp(user))
            {
                string header = configuration()->decorate(
                    sprintf("[ %s %s ]: ", capitalize(channelName),
                        capitalize(sender->RealName())),
                    "header", "channel", user->colorConfiguration());

                string body = configuration()->decorate(message,
                    "body", "channel", user->colorConfiguration());

                tell_object(user, header + body + "\n");             
            }
            else
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
    if (member(inherit_list(user), "lib/realizations/wizard.c") > -1)
    {
        ret += ({ "wiz", "status" });

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
    return ({});
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
    return ({});
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *getChannelsForUser(object user)
{
    return getWizardChannels(user) +
        getGuildChannels(user) +
        getRaceChannel(user) +
        getFactionChannels(user) +
        getPartyChannel(user);
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
                unregisterChannel(channel);
            }
        }
    }
}
