//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Creator;
object Member;
object Service;

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
    destruct(getService("party"));

    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database.PrepDatabase();

    mapping actor = database.Gorthaur();
    actor["name"] = "Bob";

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess.savePlayerData(actor);

    destruct(database);

    destruct(load_object("/lib/tests/support/guilds/testGuild.c"));
    object dict = getService("guilds");
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
    Creator.guildLevel("test");
    AdvanceToLevel(Creator, 4, "test");

    Member = clone_object("/lib/tests/support/services/mockPlayer.c");
    Member.Name("Fred");
    Member.joinGuild("test");
    AdvanceToLevel(Member, 2, "test");

    Service = getService("party");

    setUsers(({ Creator, Member }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Creator);
    destruct(Member);
    destruct(Service);
}

/////////////////////////////////////////////////////////////////////////////
void CanCreateParty()
{
    Service.createParty("Test party", Creator);
    object party = Creator.getParty();

    ExpectTrue(objectp(party));
    ExpectEq("Test party#Bob", party.partyName());
    ExpectEq("Test party", Creator.partyName());
    ExpectTrue(Creator == party.creator());
    ExpectEq(({ Creator }), party.members());
}

/////////////////////////////////////////////////////////////////////////////
void CanAddMember()
{
    Service.createParty("Test party", Creator);
    object party = Creator.getParty();

    party.joinParty(Member);

    ExpectEq(({ Creator, Member }), party.members());
    ExpectEq(Creator.getParty(), Member.getParty());
}

/////////////////////////////////////////////////////////////////////////////
void CanLeaveParty()
{
    Service.createParty("Test party", Creator);
    object party = Creator.getParty();

    party.joinParty(Member);

    ExpectEq(({ Creator, Member }), party.members());

    party.leaveParty(Member);

    ExpectEq(({ Creator }), party.members());
}

/////////////////////////////////////////////////////////////////////////////
void CreatorLeavingPartySetsNewCreator()
{
    Service.createParty("Test party", Creator);
    object party = Creator.getParty();

    party.joinParty(Member);
    party.leaveParty(Creator);

    ExpectEq(({ Member }), party.members());
    ExpectEq(Member, party.creator());
}

/////////////////////////////////////////////////////////////////////////////
void DissolvePartyDestroysParty()
{
    Service.createParty("Test party", Creator);
    object party = Creator.getParty();
    party.joinParty(Member);

    party.dissolveParty();
    ExpectEq(0, Creator.getParty(), "creator party");
    ExpectEq(0, Member.getParty(), "member party");
}

/////////////////////////////////////////////////////////////////////////////
void PartyDissolvesAfterLastMemberLeaves()
{
    Service.createParty("Test party", Creator);
    object party = Creator.getParty();

    party.joinParty(Member);
    party.leaveParty(Creator);

    ExpectEq(({ Member }), party.members());
    ExpectTrue(Member == party.creator());

    ExpectTrue(party);
    party.leaveParty(Member);
    ExpectFalse(party);
}

/////////////////////////////////////////////////////////////////////////////
void ReallocateExperienceCorrectlyDividesExperience()
{
    Service.createParty("Test party", Creator);
    object party = Creator.getParty();

    ExpectEq(6000, Creator.effectiveExperience());
    Creator.addExperience(100);
    ExpectEq(6100, Creator.effectiveExperience());

    party.joinParty(Member);
    ExpectEq(1000, Member.effectiveExperience());

    Creator.addExperience(600);
    ExpectEq(6500, Creator.effectiveExperience());
    ExpectEq(1200, Member.effectiveExperience());

    Member.addExperience(600);
    ExpectEq(6900, Creator.effectiveExperience());
    ExpectEq(1400, Member.effectiveExperience());
}

/////////////////////////////////////////////////////////////////////////////
void AdvancingALevelModifiesExperienceAllocation()
{
    Service.createParty("Test party", Creator);
    object party = Creator.getParty();

    ExpectEq(6000, Creator.effectiveExperience());
    Creator.addExperience(100);
    ExpectEq(6100, Creator.effectiveExperience());

    Member.addExperience(2000);
    party.joinParty(Member);
    ExpectEq(3000, Member.effectiveExperience());

    Creator.addExperience(600);
    ExpectEq(6500, Creator.effectiveExperience());
    ExpectEq(3200, Member.effectiveExperience());

    Member.advanceLevel("test");
    Member.addExperience(700);
    ExpectEq(6900, Creator.effectiveExperience());
    ExpectEq(3500, Member.effectiveExperience());
}

/////////////////////////////////////////////////////////////////////////////
void PlayersUnexpectedlyLeavingAreAutomaticallyPrunedDuringAllocation()
{
    Service.createParty("Test party", Creator);
    object party = Creator.getParty();

    party.joinParty(Member);
    destruct(Creator);

    Member.addExperience(600);
    ExpectEq(1600, Member.effectiveExperience());

    ExpectEq(({ Member }), party.members());
    ExpectEq(Member, party.creator());
}

/////////////////////////////////////////////////////////////////////////////
void CanAddHenchman()
{
    Service.createParty("Test party", Creator);
    object party = Creator.getParty();

    party.joinParty(Member);

    object henchman = clone_object("/lib/realizations/henchman.c");
    henchman.Name("Earl");
    henchman.setLeader(Creator);

    ExpectEq(({ Creator, Member }), party.members());
    ExpectEq(({ Creator, Member, henchman }), party.members(1));
    ExpectEq(Creator.getParty(), henchman.getParty());
}

/////////////////////////////////////////////////////////////////////////////
void CanAddCompanion()
{
    Service.createParty("Test party", Creator);
    object party = Creator.getParty();

    party.joinParty(Member);

    object companion = clone_object("/lib/realizations/companion.c");
    companion.Name("Earl");
    companion.setLeader(Creator);

    ExpectEq(({ Creator, Member }), party.members());
    ExpectEq(({ Creator, Member, companion }), party.members(1));
    ExpectEq(Creator.getParty(), companion.getParty());
}

/////////////////////////////////////////////////////////////////////////////
void CanAddNPC()
{
    Service.createParty("Test party", Creator);
    object party = Creator.getParty();

    party.joinParty(Member);

    object npc = 
        clone_object("/areas/tol-dhurath/characters/galadhel/galadhel.c");
    npc.setLeader(Creator);

    ExpectEq(({ Creator, Member }), party.members());
    ExpectEq(({ Creator, Member, npc }), party.members(1));
    ExpectEq(Creator.getParty(), npc.getParty());
}

/////////////////////////////////////////////////////////////////////////////
void AdvancingALevelIgnoresHenchmenAndNPCs()
{
    Service.createParty("Test party", Creator);
    object party = Creator.getParty();

    object npc =
        clone_object("/areas/tol-dhurath/characters/galadhel/galadhel.c");
    npc.setLeader(Creator);

    object companion = clone_object("/lib/realizations/companion.c");
    companion.Name("Earl");
    companion.setLeader(Creator);

    object henchman = clone_object("/lib/realizations/henchman.c");
    henchman.Name("Ralph");
    henchman.setLeader(Creator);

    party.joinParty(Member);

    Creator.addExperience(3000);
    ExpectEq(8000, Creator.effectiveExperience());
    ExpectEq(2000, Member.effectiveExperience());
    ExpectEq(7000, npc.effectiveExperience());
    ExpectEq(1000, companion.effectiveExperience());
    ExpectEq(1000, henchman.effectiveExperience());
}

/////////////////////////////////////////////////////////////////////////////
void FollowingShowsCorrectList()
{
    Service.createParty("Test party", Creator);
    object party = Creator.getParty();

    object npc =
        clone_object("/areas/tol-dhurath/characters/galadhel/galadhel.c");
    npc.setLeader(Creator);

    object companion = clone_object("/lib/realizations/companion.c");
    companion.Name("Earl");
    companion.setLeader(Creator);

    object henchman = clone_object("/lib/realizations/henchman.c");
    henchman.Name("Ralph");
    henchman.setLeader(Creator);

    party.joinParty(Member);
    party.follow(Creator, Member);

    ExpectEq("Bob", party.following(npc));
    ExpectEq("Bob", party.following(companion));
    ExpectEq("Bob", party.following(henchman));
    ExpectEq("Bob", party.following(Member));
}

/////////////////////////////////////////////////////////////////////////////
void MoveFollowersMovesAllFollowers()
{
    Service.createParty("Test party", Creator);
    object party = Creator.getParty();

    object npc =
        clone_object("/areas/tol-dhurath/characters/galadhel/galadhel.c");
    npc.setLeader(Creator);

    object companion = clone_object("/lib/realizations/companion.c");
    companion.Name("Earl");
    companion.setLeader(Creator);

    object henchman = clone_object("/lib/realizations/henchman.c");
    henchman.Name("Ralph");
    henchman.setLeader(Creator);

    party.joinParty(Member);
    party.follow(Creator, Member);

    object room = 
        load_object("/lib/tests/support/environment/startingRoom.c");

    move_object(Creator, room);
    move_object(npc, room);
    move_object(companion, room);
    move_object(henchman, room);
    move_object(Member, room);

    command("w", Creator);
    ExpectEq(load_object("/lib/tests/support/environment/not-so-dark-room.c"), 
        environment(Creator));
    ExpectEq(environment(Creator), environment(npc));
    ExpectEq(environment(Creator), environment(companion));
    ExpectEq(environment(Creator), environment(henchman));
    ExpectEq(environment(Creator), environment(Member));
}

/////////////////////////////////////////////////////////////////////////////
void PartyDetailsArePersisted()
{
    // Need to first make sure the database is cleaned out
    Service.createParty("Test party", Creator);
    object party = Creator.getParty();
    party.dissolveParty();

    Service.createParty("Test party", Creator);
    party = Creator.getParty();

    object npc =
        clone_object("/areas/tol-dhurath/characters/galadhel/galadhel.c");
    npc.setLeader(Creator);

    object companion = clone_object("/lib/realizations/companion.c");
    companion.Name("Earl");
    companion.setLeader(Creator);

    object henchman = clone_object("/lib/realizations/henchman.c");
    henchman.Name("Ralph");
    henchman.setLeader(Creator);

    party.joinParty(Member);
    party.follow(Creator, Member);

    ExpectEq(5, sizeof(party.members(1)));

    // This ensures that the party is re-loaded from the DB
    destruct(party);

    party = Service.getParty(Creator);
    ExpectEq(5, sizeof(party.members(1)));
}
