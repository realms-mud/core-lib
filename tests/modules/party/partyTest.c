//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Creator;
object Member;
object Dictionary;

/////////////////////////////////////////////////////////////////////////////
int AdvanceToLevel(object user, int level, string guild)
{
    int runningLevel = user->guildLevel(guild);
    while ((user->guildLevel(guild) < level) && user->memberOfGuild(guild))
    {
        user->addExperience(1000 * runningLevel);
        user->advanceLevel(guild);
        runningLevel = user->guildLevel(guild);
    }
    return runningLevel;
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    destruct(load_object("/lib/tests/support/guilds/testGuild.c"));
    object dict = load_object("/lib/dictionaries/guildsDictionary.c");
    dict->resetCache();

    load_object("/lib/tests/support/guilds/testGuild.c");

    ignoreList += ({ "AdvanceToLevel" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Creator = clone_object("/lib/tests/support/services/mockPlayer.c");
    Creator->Name("Bob");
    Creator->joinGuild("test");
    Creator->guildLevel("test");
    AdvanceToLevel(Creator, 4, "test");

    Member = clone_object("/lib/tests/support/services/mockPlayer.c");
    Member->Name("Fred");
    Member->joinGuild("test");
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
void CanCreateParty()
{
    Dictionary->createParty("Test party", Creator);
    object party = Creator->getParty();

    ExpectTrue(objectp(party));
    ExpectEq("Test party#Bob", party->partyName());
    ExpectEq("Test party", Creator->partyName());
    ExpectTrue(Creator == party->creator());
    ExpectEq(({ Creator }), party->members());
}

/////////////////////////////////////////////////////////////////////////////
void CanAddMember()
{
    Dictionary->createParty("Test party", Creator);
    object party = Creator->getParty();

    party->joinParty(Member);

    ExpectEq(({ Creator, Member }), party->members());
    ExpectEq(Creator->getParty(), Member->getParty());
}

/////////////////////////////////////////////////////////////////////////////
void CanLeaveParty()
{
    Dictionary->createParty("Test party", Creator);
    object party = Creator->getParty();

    party->joinParty(Member);

    ExpectEq(({ Creator, Member }), party->members());

    party->leaveParty(Member);

    ExpectEq(({ Creator }), party->members());
}

/////////////////////////////////////////////////////////////////////////////
void CreatorLeavingPartySetsNewCreator()
{
    Dictionary->createParty("Test party", Creator);
    object party = Creator->getParty();

    party->joinParty(Member);
    party->leaveParty(Creator);

    ExpectEq(({ Member }), party->members());
    ExpectEq(Member, party->creator());
}

/////////////////////////////////////////////////////////////////////////////
void DissolvePartyDestroysParty()
{
    Dictionary->createParty("Test party", Creator);
    object party = Creator->getParty();
    party->joinParty(Member);

    party->dissolveParty();
    ExpectEq(0, Creator->getParty());
    ExpectEq(0, Member->getParty());
}

/////////////////////////////////////////////////////////////////////////////
void PartyDissolvesAfterLastMemberLeaves()
{
    Dictionary->createParty("Test party", Creator);
    object party = Creator->getParty();

    party->joinParty(Member);
    party->leaveParty(Creator);

    ExpectEq(({ Member }), party->members());
    ExpectTrue(Member == party->creator());

    ExpectTrue(party);
    party->leaveParty(Member);
    ExpectFalse(party);
}

/////////////////////////////////////////////////////////////////////////////
void ReallocateExperienceCorrectlyDividesExperience()
{
    Dictionary->createParty("Test party", Creator);
    object party = Creator->getParty();

    ExpectEq(6000, Creator->effectiveExperience());
    Creator->addExperience(100);
    ExpectEq(6100, Creator->effectiveExperience());

    party->joinParty(Member);
    ExpectEq(1000, Member->effectiveExperience());

    Creator->addExperience(600);
    ExpectEq(6500, Creator->effectiveExperience());
    ExpectEq(1200, Member->effectiveExperience());

    Member->addExperience(600);
    ExpectEq(6900, Creator->effectiveExperience());
    ExpectEq(1400, Member->effectiveExperience());
}

/////////////////////////////////////////////////////////////////////////////
void AdvancingALevelModifiesExperienceAllocation()
{
    Dictionary->createParty("Test party", Creator);
    object party = Creator->getParty();

    ExpectEq(6000, Creator->effectiveExperience());
    Creator->addExperience(100);
    ExpectEq(6100, Creator->effectiveExperience());

    Member->addExperience(2000);
    party->joinParty(Member);
    ExpectEq(3000, Member->effectiveExperience());

    Creator->addExperience(600);
    ExpectEq(6500, Creator->effectiveExperience());
    ExpectEq(3200, Member->effectiveExperience());

    Member->advanceLevel("test");
    Member->addExperience(700);
    ExpectEq(6900, Creator->effectiveExperience());
    ExpectEq(3500, Member->effectiveExperience());
}

/////////////////////////////////////////////////////////////////////////////
void PlayersUnexpectedlyLeavingAreAutomaticallyPrunedDuringAllocation()
{
    Dictionary->createParty("Test party", Creator);
    object party = Creator->getParty();

    party->joinParty(Member);
    destruct(Creator);

    Member->addExperience(600);
    ExpectEq(1600, Member->effectiveExperience());

    ExpectEq(({ Member }), party->members());
    ExpectEq(Member, party->creator());
}
