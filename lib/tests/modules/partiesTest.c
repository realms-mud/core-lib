//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Creator;
object Member;
object Dictionary;

/////////////////////////////////////////////////////////////////////////////
int AdvanceToLevel(object user, int level, string guild)
{
    int runningLevel = user.guildLevel(guild);
    while ((user.guildLevel(guild) < level) && user.memberOfGuild(guild))
    {
        user.addExperience(1000 * runningLevel);
        user.advanceLevel(guild);
        runningLevel = user.guildLevel(guild);
    }
    return runningLevel;
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    destruct(load_object("/lib/tests/support/guilds/testGuild.c"));
    object dict = load_object("/lib/dictionaries/guildsDictionary.c");
    dict.resetCache();

    load_object("/lib/tests/support/guilds/testGuild.c");

    ignoreList += ({ "AdvanceToLevel" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Creator = clone_object("/lib/tests/support/services/mockPlayer.c");
    Creator.Name("Bob");
    Creator.joinGuild("test");
    AdvanceToLevel(Creator, 4, "test");

    Member = clone_object("/lib/tests/support/services/mockPlayer.c");
    Member.Name("Fred");
    Member.joinGuild("test");
    AdvanceToLevel(Member, 2, "test");

    Dictionary = load_object("/lib/dictionaries/partyDictionary.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Creator);
    destruct(Member);
    destruct(Dictionary);
}

/////////////////////////////////////////////////////////////////////////////
void CanGetParty()
{
    Dictionary.createParty("Test party", Creator);
    object party = Creator.getParty();

    ExpectEq(({ "/lib/modules/party/party.c" }), inherit_list(party));
}

/////////////////////////////////////////////////////////////////////////////
void CanGetPartyName()
{
    Dictionary.createParty("Test party", Creator);
    ExpectEq("Test party", Creator.partyName());
}
