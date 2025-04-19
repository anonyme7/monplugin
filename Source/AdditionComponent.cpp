/*
  ==============================================================================

    AdditionComponent.cpp
    Created: 14 Apr 2025 10:15:31pm
    Author:  olivier

  ==============================================================================
*/

#include <JuceHeader.h>
#include "AdditionComponent.h"
#include "PluginEditor.h"

//==============================================================================
AdditionComponent::AdditionComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

AdditionComponent::~AdditionComponent()
{
}
void AdditionComponent::paint(juce::Graphics& g)
{
    // Dessiner le fond
    g.fillAll(juce::Colours::blue);

    // Dessiner le texte
    g.setColour(juce::Colours::white);
    g.drawText("+", getLocalBounds(), juce::Justification::centred);

    // Appeler la méthode de la classe de base pour dessiner la bordure
    ComponentPerso::paint(g);
}

void AdditionComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}


void AdditionComponent::setSelected(bool selected)
{
    isSelected = selected;
    repaint(); // Redessiner pour mettre à jour la bordure
}