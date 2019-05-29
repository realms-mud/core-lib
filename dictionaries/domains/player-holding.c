//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void setLayout(string layout)
{
    setTerrain(layout);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addConditionalExit(string layout,
    string condition, string direction, string path, string state)
{
    addExit(direction, path, state);
}

/////////////////////////////////////////////////////////////////////////////
public void build(string type)
{
	object dictionary = load_object("/lib/dictionaries/domainDictionary.c");

	string newDescription = dictionary->getFeatureDescription(type);

	if (newDescription)
	{
		// TODO 606
	}
}
