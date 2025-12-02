//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("seilyndria", "@S@'Seilyndria? This cannot be - she was cast "
        "into the void a long time ago. What can this mean?' @D@says "
        "Galadhel, brow furrowed in thought, fear apparent on her face.");

    addTopic("maiwyn offended", "@D@Galadhel smirks and punches "
        "##InitiatorName## in the shoulder. She leans in and in an "
        "exaggerated faux whisper says, @S@'Classy move, dipshit!' "
        "@D@She turns to Maiwyn and gently says, @S@'Excuse my boorish "
        "friend, dear. @C@##ActorSubjective## is a bit of an "
        "acquired taste, but ##ActorSubjective## means well. "
        "@C@##ActorSubjective## meant simply to marvel that you "
        "were not dead, not to imply that you had joined this man who "
        "means our kingdom ill.");
}
