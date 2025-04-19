/*
  ==============================================================================

    ComponentPerso.cpp
    Created: 19 Apr 2025 9:17:10pm
    Author:  olivier

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ComponentPerso.h"
#include "PluginEditor.h"

//==============================================================================
ComponentPerso::ComponentPerso()
{
    setSize(50, 50);

}

ComponentPerso::~ComponentPerso()
{
}

void ComponentPerso::paint (juce::Graphics& g)
{
    if (isSelected)
    {
        g.setColour(juce::Colours::red);
        g.drawRect(getLocalBounds(), 2.0f); // Bordure rouge, épaisseur 2 pixels
    }
}

void ComponentPerso::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}


void ComponentPerso :: mouseDown(const juce::MouseEvent& event)
{
    if (auto* editor = dynamic_cast<MonpluginAudioProcessorEditor*>(getParentComponent()))
        editor->selectComponent(this);
}


void ComponentPerso :: setSelected(bool selected)
{
    isSelected = selected;
    repaint(); // Redessiner pour mettre à jour la bordure
}

bool ComponentPerso :: isComponentSelected() const { return isSelected; }



