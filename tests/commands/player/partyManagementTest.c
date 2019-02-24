//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Member;
object Dictionary;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->Race("human");
    Player->Con(10);
    Player->hitPoints(Player->maxHitPoints());
    Player->addCommands();

    Member = clone_object("/lib/tests/support/services/mockPlayer.c");
    Member->Name("Fred");

    setUsers(({ Player, Member }));
    Dictionary = load_object("/lib/dictionaries/partyDictionary.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Member);
    destruct(Dictionary);
}

/////////////////////////////////////////////////////////////////////////////
void CanCreateParty()
{
    command("create party New Party", Player);
    ExpectEq("New Party", Player->partyName());
    ExpectTrue(objectp(Player->getParty()));
    ExpectEq("You have created a party: New Party\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotCreatePartyWhenAlreadyInAParty()
{
    command("create party First Party", Player);
    ExpectEq("First Party", Player->partyName());
    command("create party New Party", Player);
    ExpectEq("First Party", Player->partyName());
    ExpectTrue(objectp(Player->getParty()));
    ExpectEq("You are already in a party (First Party).\n"
        "You must first leave it before joining another party.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotCreatePartyWhenNoValueGiven()
{
    command("create party", Player);

    ExpectFalse(objectp(Player->getParty()));
    ExpectEq("What?\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotLeavePartyWhenNotInAParty()
{
    command("leave party", Player);
    ExpectEq("You are not currently in a party.\n", 
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanLeaveParty()
{
    command("create party Weasels", Player);
    ExpectTrue(objectp(Player->getParty()));

    command("leave party", Player);
    ExpectFalse(objectp(Player->getParty()));
    ExpectEq("You have left your party: Weasels\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanDissolveParty()
{
    command("create party Weasels", Player);
    ExpectTrue(objectp(Player->getParty()));
    Player->getParty()->joinParty(Member);
    ExpectTrue(objectp(Member->getParty()));

    command("dissolve party", Player);
    ExpectFalse(objectp(Player->getParty()));
    ExpectFalse(objectp(Member->getParty()));

    ExpectEq("You have dissolved your party: Weasels\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotDissolvePartiesYouDoNotOwn()
{
    command("create party Weasels", Player);
    ExpectTrue(objectp(Player->getParty()));
    Player->getParty()->joinParty(Member);
    ExpectTrue(objectp(Member->getParty()));

    command("dissolve party", Member);
    ExpectTrue(objectp(Player->getParty()));
    ExpectTrue(objectp(Member->getParty()));

    ExpectEq("Only the creator of the party can dissolve it.\n",
        Member->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanAddPartyMember()
{
    command("create party Weasels", Player);
    ExpectTrue(objectp(Player->getParty()));
    
    command("add party member fred", Player);

    ExpectTrue(Dictionary->hasPendingPartyRequest(Member));

    ExpectEq("You have added Fred to your party: Weasels\n",
        Player->caughtMessage());
    ExpectEq("You have a pending invite to join a party: Weasels (Bob)\n"
        "Type 'accept party invite' to join this party.\n",
        Member->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddPartyMemberWhenNotInParty()
{
    command("add party member fred", Player);

    ExpectFalse(Dictionary->hasPendingPartyRequest(Member));

    ExpectEq("You must first create a party.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddPartyMemberWhenPlayerDoesNotExist()
{
    command("add party member earl", Player);

    ExpectEq("Could not find a player named Earl.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddPartyMemberWhenTheyAreAlreadyInAParty()
{
    command("create party Weasels", Player);
    command("create party blarg", Member);

    command("add party member fred", Player);

    ExpectEq("Fred is already in a party (blarg).\n"
        "They must first leave it before joining another party.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanAcceptPartyInvitation()
{
    command("create party Weasels", Player);
    ExpectTrue(objectp(Player->getParty()));

    command("add party member fred", Player);
    ExpectFalse(objectp(Member->getParty()));
    ExpectTrue(Dictionary->hasPendingPartyRequest(Member));

    command("accept party invite", Member);
    ExpectTrue(objectp(Member->getParty()));

    ExpectEq("You have joined the 'Weasels' party (Bob)\n",
        Member->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AcceptPartyInvitationFailsWhenNoInviteIsPending()
{
    command("accept party invite", Member);
    ExpectFalse(objectp(Member->getParty()));

    ExpectEq("You do not have a pending party invitation.\n",
        Member->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanRemovePartyMember()
{
    command("create party Weasels", Player);
    command("add party member fred", Player);
    command("accept party invite", Member);
    ExpectTrue(objectp(Member->getParty()));

    command("remove party member fred", Player);
    ExpectFalse(objectp(Member->getParty()));

    ExpectEq("You have removed Fred from your party: Weasels\n",
        Player->caughtMessage());
    ExpectEq("You have been removed from the party: Weasels (Bob)\n",
        Member->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotRemovePartyMemberWhenNotCreator()
{
    command("create party Weasels", Player);
    command("add party member fred", Player);
    command("accept party invite", Member);
    ExpectTrue(objectp(Member->getParty()));

    command("remove party member bob", Member);
    ExpectTrue(objectp(Player->getParty()));

    ExpectEq("Only the party's creator/owner (Bob) can remove members.\n",
        Member->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotRemoveNonexistantPartyMember()
{
    command("create party Weasels", Player);
    command("remove party member tantor the unclean", Player);

    ExpectEq("There is nobody named 'Tantor the unclean' in your party.\n",
        Player->caughtMessage());
}
