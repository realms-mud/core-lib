//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Member;
object Service;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database.PrepDatabase();
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.Race("human");
    Player.Con(10);
    Player.hitPoints(Player.maxHitPoints());
    Player.addCommands();

    Member = clone_object("/lib/tests/support/services/mockPlayer.c");
    Member.Name("Fred");

    setUsers(({ Player, Member }));
    Service = getService("party");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Member);
    destruct(Service);
}

/////////////////////////////////////////////////////////////////////////////
void CanCreateParty()
{
    command("create party New Party", Player);
    ExpectEq("New Party", Player.partyName());
    ExpectTrue(objectp(Player.getParty()));
    ExpectEq("You have created a party: New Party\n", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotCreatePartyWhenAlreadyInAParty()
{
    command("create party First Party", Player);
    ExpectEq("First Party", Player.partyName());
    command("create party New Party", Player);
    ExpectEq("First Party", Player.partyName());
    ExpectTrue(objectp(Player.getParty()));
    ExpectEq("You are already in a party (First Party).\n"
        "You must first leave it before joining another party.\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotCreatePartyWhenNoValueGiven()
{
    command("create party", Player);

    ExpectFalse(objectp(Player.getParty()));
    ExpectEq("What?\n", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotLeavePartyWhenNotInAParty()
{
    command("leave party", Player);
    ExpectEq("You are not currently in a party.\n", 
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanLeaveParty()
{
    command("create party Weasels", Player);
    ExpectTrue(objectp(Player.getParty()));

    command("leave party", Player);
    ExpectFalse(objectp(Player.getParty()));
    ExpectSubStringMatch("Bob has left the party",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanDissolveParty()
{
    command("create party Weasels", Player);
    ExpectTrue(objectp(Player.getParty()));
    Player.getParty().joinParty(Member);
    ExpectTrue(objectp(Member.getParty()));

    command("dissolve party", Player);
    ExpectFalse(objectp(Player.getParty()));
    ExpectFalse(objectp(Member.getParty()));

    ExpectEq("You have dissolved your party: Weasels\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotDissolvePartiesYouDoNotOwn()
{
    command("create party Weasels", Player);
    ExpectTrue(objectp(Player.getParty()));
    Player.getParty().joinParty(Member);
    ExpectTrue(objectp(Member.getParty()));

    command("dissolve party", Member);
    ExpectTrue(objectp(Player.getParty()));
    ExpectTrue(objectp(Member.getParty()));

    ExpectEq("Only the creator of the party can dissolve it.\n",
        Member.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanAddPartyMember()
{
    command("create party Weasels", Player);
    ExpectTrue(objectp(Player.getParty()));
    
    command("add party member fred", Player);

    ExpectTrue(Service.hasPendingPartyRequest(Member));

    ExpectEq("You have added Fred to your party: Weasels\n",
        Player.caughtMessage());
    ExpectEq("You have a pending invite to join a party: Weasels (Bob)\n"
        "Type 'accept party invite' to join this party.\n",
        Member.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddPartyMemberWhenNotInParty()
{
    command("add party member fred", Player);

    ExpectFalse(Service.hasPendingPartyRequest(Member));

    ExpectEq("You must first create a party.\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddPartyMemberWhenPlayerDoesNotExist()
{
    command("add party member earl", Player);

    ExpectEq("Could not find a player named Earl.\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddPartyMemberWhenTheyAreAlreadyInAParty()
{
    command("create party Weasels", Player);
    command("create party blarg", Member);

    command("add party member fred", Player);

    ExpectEq("Fred is already in a party (blarg).\n"
        "They must first leave it before joining another party.\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanAcceptPartyInvitation()
{
    command("create party Weasels", Player);
    ExpectTrue(objectp(Player.getParty()));

    command("add party member fred", Player);
    ExpectFalse(objectp(Member.getParty()));
    ExpectTrue(Service.hasPendingPartyRequest(Member));

    command("accept party invite", Member);
    ExpectTrue(objectp(Member.getParty()));

    ExpectEq("You have joined the 'Weasels' party (Bob)\n",
        Member.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AcceptPartyInvitationFailsWhenNoInviteIsPending()
{
    command("accept party invite", Member);
    ExpectFalse(objectp(Member.getParty()));

    ExpectEq("You do not have a pending party invitation.\n",
        Member.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanRemovePartyMember()
{
    command("create party Weasels", Player);
    command("add party member fred", Player);
    command("accept party invite", Member);
    ExpectTrue(objectp(Member.getParty()));

    command("remove party member fred", Player);
    ExpectFalse(objectp(Member.getParty()));

    ExpectSubStringMatch("Fred has been removed from the party",
        Player.caughtMessage());
    ExpectSubStringMatch("Fred has been removed from the party",
        Member.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotRemovePartyMemberWhenNotCreator()
{
    command("create party Weasels", Player);
    command("add party member fred", Player);
    command("accept party invite", Member);
    ExpectTrue(objectp(Member.getParty()));

    command("remove party member bob", Member);
    ExpectTrue(objectp(Player.getParty()));

    ExpectEq("Only the party's creator/owner (Bob) can remove members.\n",
        Member.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotRemoveNonexistantPartyMember()
{
    command("create party Weasels", Player);
    command("remove party member tantor the unclean", Player);

    ExpectEq("There is nobody named 'Tantor the unclean' in your party.\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanTalkOnPartyChannel()
{
    command("create party Weasels", Player);
    command("add party member fred", Player);
    command("accept party invite", Member);

    command("party Hi there!", Player);
    ExpectSubStringMatch("Weasels Bob.*Hi there!",
        Player.caughtMessage());
    ExpectSubStringMatch("Weasels Bob.*Hi there!",
        Member.caughtMessage());

    command("party Bite me!", Member);
    ExpectSubStringMatch("Weasels Fred.*Bite me!",
        Player.caughtMessage());
    ExpectSubStringMatch("Weasels Fred.*Bite me!",
        Member.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanFollowPartyMember()
{
    move_object(Player, "/lib/tests/support/environment/startingRoom.c");
    move_object(Member, "/lib/tests/support/environment/startingRoom.c");
    command("create party Weasels", Player);
    command("add party member fred", Player);
    command("accept party invite", Member);
    ExpectTrue(objectp(Member.getParty()));

    command("follow party member fred", Player);

    ExpectSubStringMatch("Bob is now following Fred",
        Player.caughtMessage());
    ExpectSubStringMatch("Bob is now following Fred",
        Member.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanNotFollowPartyMemberWhenNotPresent()
{
    move_object(Player, "/lib/tests/support/environment/startingRoom.c");
    move_object(Member, "/lib/tests/support/environment/darkRoom.c");
    command("create party Weasels", Player);
    command("add party member fred", Player);
    command("accept party invite", Member);
    ExpectTrue(objectp(Member.getParty()));

    Player.resetCatchList();
    Member.resetCatchList();

    command("follow party member fred", Player);

    ExpectSubStringMatch("You must both be in the same location",
        Player.caughtMessage());
    ExpectEq(0, Member.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanNotFollowNonPartyMembers()
{
    move_object(Player, "/lib/tests/support/environment/startingRoom.c");
    move_object(Member, "/lib/tests/support/environment/startingRoom.c");
    command("create party Weasels", Player);

    Player.resetCatchList();
    Member.resetCatchList();

    command("follow party member fred", Player);

    ExpectSubStringMatch("There is nobody named 'Fred' in your party",
        Player.caughtMessage());
    ExpectEq(0, Member.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanNotFollowWhenNotInAParty()
{
    move_object(Player, "/lib/tests/support/environment/startingRoom.c");
    move_object(Member, "/lib/tests/support/environment/startingRoom.c");

    Player.resetCatchList();
    Member.resetCatchList();

    command("follow party member fred", Player);

    ExpectSubStringMatch("You are not currently in a party",
        Player.caughtMessage());
    ExpectEq(0, Member.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanNotFollowPartyMemberWhenAlreadyFollowingSomeoneElse()
{
    move_object(Player, "/lib/tests/support/environment/startingRoom.c");
    move_object(Member, "/lib/tests/support/environment/startingRoom.c");
    command("create party Weasels", Player);
    command("add party member fred", Player);
    command("accept party invite", Member);
    ExpectTrue(objectp(Member.getParty()));

    command("follow party member fred", Player);

    Player.resetCatchList();
    Member.resetCatchList();

    command("follow party member fred", Player);

    ExpectSubStringMatch("You are currently following Fred.*"
        "If you wish to follow someone else, stop following",
        Player.caughtMessage());
    ExpectEq(0, Member.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanStopFollowingPartyMemberYouAreFollowing()
{
    move_object(Player, "/lib/tests/support/environment/startingRoom.c");
    move_object(Member, "/lib/tests/support/environment/startingRoom.c");
    command("create party Weasels", Player);
    command("add party member fred", Player);
    command("accept party invite", Member);
    ExpectTrue(objectp(Member.getParty()));

    command("follow party member fred", Player);

    Player.resetCatchList();
    Member.resetCatchList();

    command("stop following party member", Player);

    ExpectSubStringMatch("Bob is no longer following Fred*",
        Player.caughtMessage());
    ExpectSubStringMatch("Bob is no longer following Fred*",
        Member.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanUseStopFollowingToStopFollowingPartyMember()
{
    move_object(Player, "/lib/tests/support/environment/startingRoom.c");
    move_object(Member, "/lib/tests/support/environment/startingRoom.c");
    command("create party Weasels", Player);
    command("add party member fred", Player);
    command("accept party invite", Member);
    ExpectTrue(objectp(Member.getParty()));

    command("follow party member fred", Player);

    Player.resetCatchList();
    Member.resetCatchList();

    command("stop following", Player);

    ExpectSubStringMatch("Bob is no longer following Fred*",
        Player.caughtMessage());
    ExpectSubStringMatch("Bob is no longer following Fred*",
        Member.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanNotStopFollowingWhenNotFollowingAnybodyy()
{
    move_object(Player, "/lib/tests/support/environment/startingRoom.c");
    move_object(Member, "/lib/tests/support/environment/startingRoom.c");
    command("create party Weasels", Player);
    command("add party member fred", Player);
    command("accept party invite", Member);
    ExpectTrue(objectp(Member.getParty()));

    Player.resetCatchList();
    Member.resetCatchList();

    command("stop following party member", Player);

    ExpectSubStringMatch("You are not following anybody",
        Player.caughtMessage());
    ExpectEq(0, Member.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanNotStopFollowingWhenNotInParty()
{
    move_object(Player, "/lib/tests/support/environment/startingRoom.c");
    move_object(Member, "/lib/tests/support/environment/startingRoom.c");

    Player.resetCatchList();
    Member.resetCatchList();

    command("stop following party member", Player);

    ExpectSubStringMatch("You are not currently in a party",
        Player.caughtMessage());
    ExpectEq(0, Member.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MemberFollowsPartyLeader()
{
    object startingRoom = 
        load_object("/lib/tests/support/environment/startingRoom.c");
    object nextRoom = 
        load_object("/lib/tests/support/environment/not-so-dark-room.c");

    move_object(Player, startingRoom);
    move_object(Member, startingRoom);
    command("create party Weasels", Player);
    command("add party member fred", Player);
    command("accept party invite", Member);
    ExpectTrue(objectp(Member.getParty()));

    command("follow party member bob", Member);

    ExpectEq(startingRoom, environment(Player));
    ExpectEq(startingRoom, environment(Member));

    command("w", Player);
    ExpectEq(nextRoom, environment(Player));
    ExpectEq(nextRoom, environment(Member));
}