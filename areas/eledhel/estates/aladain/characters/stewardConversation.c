//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Ellisar sets a seal beside "
        "the open ledger. @S@'House Aladain's records are kept here. "
        "The village reeve handles the crop and water tallies.'");
    addTopic("the holdings", "@S@'The keep, its fields, and the "
        "village answer to the same household. A road grant or a "
        "work contract is not a transfer of the estate.'");
    addResponse("first conversation", "Who owns the estate?",
        "@S@'House Aladain holds the keep, fields, and village.'");
    addResponseTopic("first conversation", "Who owns the estate?",
        "the holdings");
    addResponse("the holdings", "Can I claim a field by working it?",
        "@S@'No. The household keeps title to the estate. Speak "
        "with the reeve about work or an agreed use of the land.'");
}
