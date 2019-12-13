//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
private void ViliasAppears()
{
    addTopic("first conversation", "@D@Some mist forms a few feet to the "
        "east. As it thickens, it begins to take form. The figure looks "
        "vaguely humanoid. As the mist coalesces, it takes on the form of a "
        "woman dressed in a flowing midnight blue robe. She is a tall, "
        "raven-haired, grey-eyed woman of surpassing beauty. She doesn't look "
        "quite human - whether that's due to her visage or the fact that "
        "she's ethereal is unclear.\n\nSensing the party tense, she smiles "
        "brightly and says in a pleasant, somewhat demure voice, @S@'Nay, I "
        "am no foe. In fact, you should thank me.' @D@She grins impishly at "
        "this and, in a sweet, musical voice adds, @S@'For you were about "
        "to get yourselves killed.'");


}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    ViliasAppears();
}
