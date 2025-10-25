#include "Core.h"

#include "ImGuiLayer.h"
#include "AppLayer.h"

int main(int argc, char** argv)
{
  Core::ApplicationSpecification appSpec;
  appSpec.name = "nevi";
  appSpec.windowSpec.width = 1000;
  appSpec.windowSpec.height = 1000;

  Core::Application application(appSpec);
  application.pushLayer<AppLayer>();
  application.pushLayer<ImGuiLayer>();
  application.run();
}