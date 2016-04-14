defmodule Spockex do
  @moduledoc """
    A Vulkan Driver for Erlang/Elixir
  """

  @on_load { :init, 0 }

  app = Mix.Project.config[:app]

  def init do
    path = :filename.join(:code.priv_dir(unquote(app)), 'spockex')
    :ok = :erlang.load_nif(path, 0)
  end

  @doc ~S"""
  Displays info

    iex> Spockex.info
    :"0"
  """
  def info do
    exit(:nif_library_not_loaded)
  end

end
