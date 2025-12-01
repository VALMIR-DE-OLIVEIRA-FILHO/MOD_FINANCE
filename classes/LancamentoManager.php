<?php
require_once "Lancamento.php";

class LancamentoManager {

    private $file;

    public function __construct($filePath) {
        $this->file = $filePath;
        if (!file_exists($filePath)) {
            file_put_contents($filePath, "");
        }
    }

    public function listar() {
        $linhas = file($this->file, FILE_IGNORE_NEW_LINES);
        $lista = [];

        foreach ($linhas as $linha) {
            if (trim($linha) !== "") {
                $lista[] = Lancamento::fromLine($linha);
            }
        }
        return $lista;
    }

    public function adicionar(Lancamento $l) {
        file_put_contents($this->file, $l->toLine() . PHP_EOL, FILE_APPEND);
    }

    public function limpar() {
        file_put_contents($this->file, "");
    }
}
