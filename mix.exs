defmodule Spockex.Mixfile do
  use Mix.Project

  @version String.strip(File.read!("VERSION"))

  def project do
    [app: :spockex,
     version: @version,
     elixir: "~> 1.2",
     compilers: [:elixir, :app],
     deps: deps]
  end

  def application do
    []
  end

  defp deps do
    [
      # vulkan headers must be installed in /usr/include/vulkan
    ]
  end

end
