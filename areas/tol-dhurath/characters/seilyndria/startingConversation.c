//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
private void SeilyndriaAppears()
{
    addTopic("first conversation", "@D@A rather surprised-looking woman "
        "dressed in a dirty tan-ish shirt and equally dirty pants stands "
        "before you. Her garments are both made of coarse, thread-bare linen "
        "and show signs of excessive mistreatment. There are many stains - "
        "some of blood and some of what appear to be porridge. She smells of "
        "sweat, urine, feces, and rotting food. Her amber hair is disheveled "
        "and rather filthy. Dirt, bruises, and abrasions mark her face. "
        "All of the abuse and neglect does not obscure the fact that she "
        "is an incredibly attractive woman. Her pale blue eyes open a window "
        "into a tortured, despairing soul. She shakily, but menacingly, "
        "snarls @S@'Nay! Nay, I will not go back!' @D@She brandishes a "
        "broken candelabra at you and then pauses. @S@'Wait. You are not my "
        "tormentors. Who are you?'");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    SeilyndriaAppears();
}
